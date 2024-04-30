#include "div.h"
void			efadd_picture(t_div			*div,
				      t_zposition		pos,
				      t_bunny_size		size,
				      const char		*name,
				      const char		*filename)
{
  div->picture->name = name;
  div->picture->pos = pos;
  div->picture->size = size;
  div->picture->filname = filname;
}
