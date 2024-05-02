#include		"draw.h"

int			get_npos(int		width,
				 t_bunny_position	pos)
{
  return((pos.y * width) + pos.x);
}
