#include                "lab.h"

void                    efletter(t_bunny_zpixelarray    *pix,
                                 t_bunny_pixelarray     *font,
                                 t_zposition		*pos,
				 t_bunny_color		*col,
                                 char                   c)
{
  t_bunny_clipable	tmp;

  if (pix->z[pos->x + pos->y * pix->px->clipable.buffer.width] > pos->z)
    {
      bunny_clipable_copy(&tmp, &font->clipable);
      font->clipable.clip_x_position = c * 10;
      font->clipable.clip_y_position = 0;
      font->clipable.clip_width = 10;
      blit(pix, font, pos, col);

      bunny_clipable_copy(&font->clipable, &tmp);
    }
  return;
}
