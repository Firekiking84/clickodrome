#include "div.h"
void			efdisplay_div(t_div			*div,
				      t_bunny_zpixelarray	*px)
{
  size_t count;

    count = 0;
    while (count < div->labels->data_count)
    {
      efdisplay_label(efvector_ptr_get(div->labels, count), px);
      count++;
    }
  count = 0;
  while (count < div->buttons->data_count)
    {
      efdisplay_button(efvector_ptr_get(div->buttons,count), px);
      count++;
    }
  count = 0;
  while (count < div->text_boxes->data_count)
    {
      efdisplay_text_box(efvector_ptr_get(div->text_boxes, count), px);
      count++;
    }
  count =0;
  while (count < div->pictures->data_count)
    {
      efdisplay_picture(efvector_ptr_get(div->pictures,count), px);
      count++;
    }
}
