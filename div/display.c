#include "div.h"
void			efdisplay_div(t_div			*div,
				      t_bunny_pixelarray	*px)
{
  size_t count;

    count = 0;
    while (count < div->labels->data_count)
    {
      efdisplay_label(efvector_at(div->labels, count, t_label), px);
      count++;
    }
  count = 0;
  while (count < div->buttons->data_count)
    {
      efdisplay_button(efvector_at(div->buttons,count,t_button), px);
      count++;
    }
  count = 0;
  while (count < div->text_boxes->data_count)
    {
      efdisplay_text_box(efvector_at(div->text_boxes, count,t_text_box), px);
      count++;
    }
  count =0;
  while (count < div->pictures->data_count)
    {
      efdisplay_picture(efvector_at(div->pictures,count,t_picture), px);
      count++;
    }
}
