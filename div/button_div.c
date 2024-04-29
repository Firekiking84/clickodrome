#include "div.h"
void			efadd_button_div(t_div				*div,
					 const char			*name,
					 t_zposition		pos,
					 t_bunny_size			size,
					 const char			*text,
					 t_bunny_color			*font_color,
					 t_bunny_color			*hover_color,
					 t_bunny_color			*bg,
					 t_vector		        *functions)
{
  div->buttons->name = name;
  div->buttons->pos = pos;
  div->buttons->size = size;
  div->buttons->texte = texte;
  div->buttons->font_color = font_color;
  div->buttons->hover_color = hover_color;
  div->buttons->bg = bg;
  div->buttons->functions= functions;
}
