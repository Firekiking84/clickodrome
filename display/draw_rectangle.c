#include		"draw.h"

void		        draw_rectangle(t_bunny_zpixelarray	*px,
				       t_zposition		*posStart,
				       t_zposition		*posEnd,
				       t_bunny_color		*col)
{
  t_zposition		drawPos;

  if (posStart->x < 0)
    posStart->x = 0;
  if (posStart->x >= px->px->clipable.buffer.width)
    posStart->x = px->px->clipable.buffer.width - 1;
  if (posEnd->x < 0)
    posEnd->x = 0;
  if (posEnd->x >= px->px->clipable.buffer.width)
    posEnd->x = px->px->clipable.buffer.width - 1;
  if (posStart->y < 0)
    posStart->y = 0;
  if (posStart->y >= px->px->clipable.buffer.height)
    posStart->y = px->px->clipable.buffer.height - 1;
  if (posEnd->y < 0)
    posEnd->y = 0;
  if (posEnd->y >= px->px->clipable.buffer.height)
    posEnd->y = px->px->clipable.buffer.height;
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
