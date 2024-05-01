#include "div.h"

void			efadd_text_box_div(t_div		*div,
					   t_textbox_settings	*settings)
{
  efvector_push(div->text_boxes, efnew_text_box_div(settings));
}
