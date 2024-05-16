#include		"gui.h"

#include		<stdio.h>

void			efdelete_elem_div(t_div		*div,
					  const char	*elem_name)
{
  size_t		i;
  t_text_box		*textbox;
  t_picture		*picture;
  t_timer		*timer;

  if (efdelete_label_div(div, elem_name))
    return;
  if (efdelete_button_div(div, elem_name))
    return;
  if (efdelete_textbox_div(div, elem_name))
    return;
  if (efdelete_picture_div(div, elem_name))
    return;
  if (efdelete_timer_div(div, elem_name))
    return;
  dprintf(2, "Cannot find elem name : %s\n", elem_name);
}
