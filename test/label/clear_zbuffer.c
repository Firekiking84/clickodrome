#include		"lab.h"

void			efclear_zbuffer(t_bunny_zpixelarray		*zpx)
{
  int			i;

  i = -1;
  while (++i < zpx->px->clipable.buffer.width * zpx->px->clipable.buffer.height)
    zpx->z[i] = 1000000000000000;
}
