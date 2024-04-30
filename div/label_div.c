#include "div.h"
void			efadd_label(t_div			*div,
				    t_zposition			pos,
				    const char			*name,
				    t_bunny_size		size,
				    const char			*text,
				    t_bunny_color		*font_color,
				    t_bunny_color		*bg)
{
  efnew_label(name ,pos ,size ,text ,font_color ,bg);
}
