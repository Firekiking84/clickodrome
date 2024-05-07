#include		"div.h"

t_div			*efnew_div(const char			*name,
				   t_bunny_position  		pos,
				   t_bunny_size			size)
{
  t_div			*div;

  div = bunny_malloc(sizeof(t_div));
  if (!div)
    return(NULL);
  div->name = name;
  div->pos = pos;
  div->size = size;
  div->end_pos.x = div->pos.x + div->size.x;
  div->end_pos.y = div->pos.y + div->size.y;
  div->in_div = false;
  div->labels = efvector_ptr_new(0);
  div->buttons = efvector_ptr_new(0);
  div->text_boxes = efvector_ptr_new(0);
  div->pictures = efvector_ptr_new(0);
  div->timers = efvector_ptr_new(0);
  return(div);
}
