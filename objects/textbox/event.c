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

int			efevent_text_box(t_text_box			*text_box,
					 const t_bunny_event		*event)
{
  if (manage_mouse_button_event(text_box, event))
    return(-2);
  else if (text_box->has_focus)
    {
      if (manage_text_event(text_box, event))
	return(text_box->order);
      manage_key_event(text_box, event);
      return(text_box->order);
    }
  return(-2);
}
