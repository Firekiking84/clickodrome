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
  div->text_box->name = name;
  div->text_box->pos = pos;
  div->text_box->size = size;
  div->text_box->texte = texte;
  div->text_box->font_color = font_color;
  div->text_box->bg = bg;
  div->text_box->functions= functions;
}
