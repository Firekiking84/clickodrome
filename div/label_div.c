#include "div.h"
void			efadd_label(t_div			*div,
				    t_zposition		pos,
				    const char			*name,
				    t_bunny_size		size,
				    const char			*text,
				    t_bunny_color		*font_color,
				    t_bunny_color		*bg)
{
  div->labels->name = name;
  div->labels->pos = pos;
  div->labels->size = size;
  div->labels->text = text;
  div->labels->font_color = font_color;
  div->labels->bg = bg;
}
