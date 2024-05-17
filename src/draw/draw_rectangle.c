#include		"draw.h"

void		        draw_rectangle(t_bunny_pixelarray	*px,
				       t_bunny_position		*posStart,
				       t_bunny_position		*posEnd,
				       t_bunny_color		*col)
{
  t_bunny_position	drawPos;

  drawPos.y = posStart->y;
  while (drawPos.y < posEnd->y)
    {
      drawPos.x = posStart->x;
      while (drawPos.x < posEnd->x)
	{
	  set_pixel(px, drawPos, col);
	  drawPos.x += 1;
	}
      drawPos.y += 1;
    }
}
