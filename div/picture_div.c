#include "div.h"
void			efadd_picture(t_div			*div,
				      const char		*name,
				      t_bunny_position		pos,
				      t_bunny_size		size,
				      const char		*filename)
{
  div->picture->name = name;
  div->picture->pos = pos;
  div->picture->size = size;
  div->picture->filname = filname;
}
