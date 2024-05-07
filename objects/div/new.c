#include		"div.h"

t_div			*efnew_div(const char			*name,
				   t_zposition  		pos,
				   t_bunny_size			size)
{
  t_div			div;

  div.name = name;
  div.pos = pos;
  div.size = size;
  div.end_pos.x = div.pos.x + div.size.x;
  div.end_pos.y = div.pos.y + div.size.y;
  div.in_div = false;
  div.labels = efvector_new(t_vector, 3);
  div.buttons = efvector_new(t_vector, 3);
  div.text_boxes = efvector_new(t_vector, 3);
  div.pictures = efvector_new(t_vector, 3);
  div.timer = efvector_new(t_vector, 3);
}
