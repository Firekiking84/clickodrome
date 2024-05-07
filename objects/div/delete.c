#include "div.h"
void			efdelete_div(t_div			*div)
{
  efvector_ptr_delete(div->labels);
  efvector_ptr_delete(div->buttons);
  efvector_ptr_delete(div->text_boxes);
  efvector_ptr_delete(div->pictures);
  efvector_ptr_delete(div->timers);
  bunny_free(div);
}
