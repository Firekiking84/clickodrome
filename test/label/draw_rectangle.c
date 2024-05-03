#include		"lab.h"

void		        draw_rectangle(t_bunny_zpixelarray	*px,
				       t_zposition		*posStart,
				       t_zposition		*posEnd,
				       t_bunny_color		*col)
{
  t_zposition		drawPos;

  drawPos.y = posStart->y;
  while (drawPos.y < posEnd->y)
    {
      drawPos.x = posStart->x;
      while ( drawPos.x < posEnd->x)
	{
	  drawPos.z = posStart->z;
	  set_zpixel(px, &drawPos, col);
	  drawPos.x += 1;
	}
      drawPos.y += 1;
    }
}
