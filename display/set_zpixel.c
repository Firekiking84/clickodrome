#include		"draw.h"

void			set_zpixel(t_bunny_zpixelarray	*px,
				   t_zposition		*pos,
				   t_bunny_color	*col)
{
  t_bunny_color		newcol;
  unsigned int		*tab;
  int			npos;

  if (pos->z > px->z[pos->x + pos->y * px->px->clipable.buffer.width]
      || col->argb[ALPHA_CMP] < 5)
    return;
  px->z[pos->x + pos->y * px->px->clipable.buffer.width] = pos->z;
  tab = (unsigned int *)px->px->pixels;
  npos = pos->y * px->px->clipable.buffer.width + pos->x;
  if (col->argb[ALPHA_CMP] != 255)
    {
      t_bunny_color	oldcol;
      double		ratio;

      oldcol.full = tab[npos];
      ratio = get_ratio(0, 255, col->argb[ALPHA_CMP]);
      newcol.argb[RED_CMP] = oldcol.argb[RED_CMP] * (1 - ratio) + col->argb[RED_CMP] * ratio;
      newcol.argb[BLUE_CMP] = oldcol.argb[BLUE_CMP] * (1 - ratio) + col->argb[BLUE_CMP] * ratio;
      newcol.argb[GREEN_CMP] = oldcol.argb[GREEN_CMP] * (1 - ratio) + col->argb[GREEN_CMP] * ratio;
      newcol.argb[ALPHA_CMP] = 255;
    }
  else
    newcol = *col;
  tab[npos] = newcol.full;
}
