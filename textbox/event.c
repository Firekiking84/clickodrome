#include		"text_box.h"

#include		<stdio.h>

static bool		check_mouse_button(t_text_box			*text_box,
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

void			efevent_text_box(t_text_box			*text_box,
					 const t_bunny_event		*event)
{
  uint8_t		byte;
  uint8_t		check;
  size_t		i;
  void			(*func_ptr)(const char *);

  if (event->type == BET_MOUSE_BUTTON_PRESSED)
    text_box->pressed_in = check_mouse_button(text_box, event->mouse_button);
  else if (event->type == BET_MOUSE_BUTTON_RELEASED)
    {
      if (text_box->pressed_in == true && check_mouse_button(text_box, event->mouse_button) == true)
	text_box->has_focus = true;
    }
  else if (text_box->has_focus)
    {
      if (event->type == BET_TEXT_ENTERED)
	{
	  byte = event->text.unicode & 0xFF;
	  check = byte >> 7;
	  if (!check & 0b1 && byte >= 32 && byte <= 126)
	    {
	      string_push_back(text_box->text, (char)event->text.unicode);
	      text_box->cursor_pos += 1;
	    }
	}
      else if (event->type == BET_KEY_PRESSED)
	{
	  if (!event->key.alt && !event->key.control && !event->key.shift && !event->key.system)
	    {
	      if (event->key.sym == BKS_RETURN)
		{
		  i = 0;
		  while (i < text_box->functions->data_count)
		    {
		      func_ptr = (void *)efvector_at(text_box->functions, i, size_t);
		      func_ptr(string_get_content(text_box->text));
		      i += 1;
		    }
		  string_clear(text_box->text);
		  text_box->cursor_pos = 0;
		}
	      else if (event->key.sym == BKS_BACKSPACE && text_box->cursor_pos > 0)
		{
		  text_box->cursor_pos -= 1;
		  string_erase(text_box->text, text_box->cursor_pos);
		}
	      else if (event->key.sym == BKS_DELETE)
		string_erase(text_box->text, text_box->cursor_pos);
	      else if (event->key.sym == BKS_LEFT && text_box->cursor_pos > 0)
		text_box->cursor_pos -= 1;
	      else if (event->key.sym == BKS_RIGHT && text_box->cursor_pos < text_box->text->str_len)
		text_box->cursor_pos += 1;
	    }
	}
    }
}
