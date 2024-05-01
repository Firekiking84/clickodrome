#include "div.h"
void			efadd_text_box_div(t_div			*div,
					   t_zposition			pos,
					   t_bunny_size			size,
					   const char			*name,
					   t_bunny_color		*font_color,
					   t_bunny_color		*bg,
					   t_vector			*functions)
{
  efvector_push(div->text_boxes, efnew_text_box_div(name ,pos ,size ,text ,font_color ,bg ,functions));
}
