#include "div.h"
void			efadd_text_box_div(t_div			*div,
					   const char			*name,
					   t_zposition			pos,
					   t_bunny_size			size,
					   const char			*text,
					   t_bunny_color		*font_color,
					   t_bunny_color		*bg,
					   t_vector			*functions)
{
  efnew_text_box_div(name ,pos ,size ,text ,font_color ,bg ,functions);
}
