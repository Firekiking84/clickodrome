#include "div.h"
size_t			efdelete_div(t_div			*div)
{
  size_t size;

  size = efvector_delete(div->labels);
  size = size + efvector_delete(div->buttons);
  size = size + efvector_delete(div->text_boxes);
  size = size + efvector_delete(div->pictures);
  size = size + efvector_delete(div->timer);
  size = size + efvector_delete(div);
  return(size);
}
