#include		"text_box.h"

bool			manage_text_event(t_text_box		*text_box,
					  const t_bunny_event	*event)
{
  uint8_t		byte;
  uint8_t		check;

  if (event->type == BET_TEXT_ENTERED)
    {
      if (text_box->selection_active)
	erase_selection(text_box);
      text_box->selection_active = false;
      byte = event->text.unicode & 0xFF;
      check = byte >> 7;
      if (!check & 0b1 && byte >= 32 && byte <= 126)
	{
	  string_insert(text_box->text, text_box->cursor_pos, (char)event->text.unicode);
	  text_box->cursor_pos += 1;
	}
    }
  else
    return(false);
  return(true);
}
