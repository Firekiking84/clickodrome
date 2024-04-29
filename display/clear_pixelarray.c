#include		"draw.h"

void			efclear_pixelarray(t_bunny_zpixelarray		*zpx,
					   unsigned int			col)
{
  int			i;
  t_bunny_color		color;

  i = -1;
  color.full = col;
  if (color.argb[ALPHA_CMP] != 255)
    {
      t_bunny_color	oldcol;
      double		ratio;

      oldcol.full = (unsigned int *)px->px->pixels[pos->y * px->px->clipable.buffer.width + pos->x];
      ratio = get_ratio(0, 255, color->argb[ALPHA_CMP]);
      color.argb[RED_CMP] = oldcol.argb[RED_CMP] * (1 - ratio) + color->argb[RED_CMP] * ratio;
      color.argb[BLUE_CMP] = oldcol.argb[BLUE_CMP] * (1 - ratio) + color->argb[BLUE_CMP] * ratio;
      color.argb[GREEN_CMP] = oldcol.argb[GREEN_CMP] * (1 - ratio) + color->argb[GREEN_CMP] * ratio;
      color.argb[ALPHA_CMP] = 255;
    }
  while (++i < zpx->px->clipable.buffer.width * zpx->px->clipable.buffer.height)
    {
      (unsigned int *)px->px->pixels[pos->y * px->px->clipable.buffer.width + pos->x] = color.full;
      zpx->z[i] = 100000000000000000;
    }
  return ;
}
