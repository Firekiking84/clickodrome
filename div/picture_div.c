#include "div.h"
void			efadd_picture(t_div			*div,
				      t_zposition		pos,
				      t_bunny_size		size,
				      const char		*name,
				      const char		*filename)
{
  efvector_push (div->pictures, efnew_picture(name ,pos ,size ,filename));
}
