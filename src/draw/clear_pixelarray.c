#include		"draw.h"

void			efclear_pixelarray(t_bunny_pixelarray		*px,
					   t_bunny_color		color)
{
  int			i;
  int			limit;

  limit = px->clipable.buffer.width * px->clipable.buffer.height;
  i = -1;
  while (++i < limit)
    ((unsigned int *)px->pixels)[i] = color.full;
}
