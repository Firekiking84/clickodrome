/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 30/04/2024 15:59:15 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"text_box.h"

#include		<stdio.h>

void			efevent_text_box(t_text_box			*text_box,
					 const t_bunny_event		*event)
{
  if (manage_mouse_button_event(text_box, event))
    return;
  else if (text_box->has_focus)
    {
      if (manage_text_event(text_box, event))
	return;
      manage_key_event(text_box, event);
    }
}
