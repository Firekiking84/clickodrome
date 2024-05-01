#include		"text_box.h"

bool			check_mouse_button(t_text_box			*text_box,
					   t_bunny_mouse_button_event	mouse_button)
{
  if (mouse_button.button == BMB_LEFT &&
      mouse_button.x >= text_box->pos.x &&
      mouse_button.x < (text_box->pos.x + text_box->size.x) &&
      mouse_button.y >= text_box->pos.y &&
      mouse_button.y < (text_box->pos.y + text_box->size.y))
    {
      return(true);
    }
  return(false);
}
