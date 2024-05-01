#include		"text_box.h"

void			manage_key_event(t_text_box			*text_box,
					 const t_bunny_event		*event)
{
  if (event->type == BET_KEY_PRESSED)
    {
      if (!event->key.alt && !event->key.control && !event->key.shift && !event->key.system)
	manage_solo_key(text_box, event);
      else if (event->key.shift && !event->key.alt && !event->key.control && !event->key.system)
	manage_shift_key(text_box, event);
      else if (event->key.control && !event->key.alt && !event->key.shift && !event->key.system)
	manage_control_key(text_box, event);
    }
}
