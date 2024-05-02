#include "div.h"

t_text_box		*efadd_text_box_div(t_div		*div,
					    t_textbox_settings	*settings)
{
  t_text_box		*new_textbox;

  new_textbox = efnew_text_box(settings);
  if (!new_textbox)
    return(NULL);
  efvector_ptr_push(div->text_boxes, new_textbox);
  return(new_textbox);
}
