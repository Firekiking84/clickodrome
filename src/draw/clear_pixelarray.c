#include		"draw.h"

void			efclear_pixelarray(t_bunny_pixelarray		*px,
					   unsigned int			col)
{
  int			i;
  t_bunny_color		color;
  int			limit;

  limit = px->clipable.buffer.width * px->clipable.buffer.height;
  i = -1;
  while (++i < limit)
    (unsigned int *)px->pixels[pos->y * px->clipable.buffer.width + pos->x] = color.full;
}
