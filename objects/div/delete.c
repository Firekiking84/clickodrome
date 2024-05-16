/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 16/05/2024 16:17:04 ******************************************************
** keryan.houssin <keryan.houssin@laika.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"div.h"

void			efdelete_div(t_div			*div)
{
  size_t 		i;

  i = 0;
  while (i < div->labels->data_count)
    {
      efdelete_label(efvector_ptr_get(div->labels, i));
      i += 1;
    }
  efvector_ptr_delete(div->labels);
  i = 0;
  while (i < div->buttons->data_count)
    {
      efdelete_button(efvector_ptr_get(div->buttons, i));
      i += 1;
    }
  efvector_ptr_delete(div->buttons);
  i = 0;
  while (i < div->text_boxes->data_count)
    {
      efdelete_text_box(efvector_ptr_get(div->text_boxes, i));
      i += 1;
    }
  efvector_ptr_delete(div->text_boxes);
  i = 0;
  while (i < div->pictures->data_count)
    {
      efdelete_picture(efvector_ptr_get(div->pictures, i));
      i += 1;
    }
  efvector_ptr_delete(div->pictures);
  i = 0;
  while (i < div->timers->data_count)
    {
      efdelete_timer(efvector_ptr_get(div->timers, i));
      i += 1;
    }
  efvector_ptr_delete(div->timers);
  bunny_free(div->name);
  bunny_free(div);
}
