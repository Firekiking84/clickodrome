#include		"text_box.h"

bool			manage_mouse_button_event(t_text_box		*text_box,
						  const t_bunny_event	*event)
{
  if (event->type == BET_MOUSE_BUTTON_PRESSED)
    {
      if (text_box->selection_active)
	text_box->selection_active = false;
      text_box->pressed_in = check_mouse_button(text_box, event->mouse_button);
      text_box->selected_area.start = get_cursor_pos(event->mouse_button.x, event->mouse_button.y, text_box);
      text_box->selected_area.end = text_box->selected_area.start;
    }
  else if (text_box->pressed_in && event->type == BET_MOUSE_MOVED)
    {
      text_box->selected_area.end = get_cursor_pos(event->mouse_moved.x, event->mouse_moved.y, text_box);
      text_box->selection_active = true;
    }
  else if (event->type == BET_MOUSE_BUTTON_RELEASED)
    {
      if (!text_box->has_focus && text_box->pressed_in == true
	  && check_mouse_button(text_box, event->mouse_button) == true)
	text_box->has_focus = true;
      else if (text_box->has_focus)
	text_box->cursor_pos = get_cursor_pos(event->mouse_button.x, event->mouse_button.y, text_box);
      text_box->pressed_in = false;
    }
  else
    return(false);
  return(true);
}
