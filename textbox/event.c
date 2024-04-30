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

static int		get_cursor_pos(int				x,
				       int				y,
				       t_text_box			*box)
{
  int			cursor_pos;

  cursor_pos = mult_arrondi(y, box->size_font.y, -1) / box->size_font.y;
  cursor_pos *= box->max_letter_on_line;
  cursor_pos += mult_arrondi(x, box->size_font.x, 0) / box->size_font.x;
  if (cursor_pos > box->text->str_len)
    cursor_pos = box->text->str_len;
  return(cursor_pos);
}

void			efevent_text_box(t_text_box			*text_box,
					 const t_bunny_event		*event)
{
  uint8_t		byte;
  uint8_t		check;
  size_t		i;
  void			(*func_ptr)(const char *);

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
  else if (text_box->has_focus)
    {
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
		  text_box->selection_active = false;
		}
	      else if (event->key.sym == BKS_BACKSPACE && text_box->cursor_pos > 0)
		{
		  text_box->cursor_pos -= 1;
		  string_erase(text_box->text, text_box->cursor_pos);
		  text_box->selection_active = false;
		}
	      else if (event->key.sym == BKS_DELETE)
		{
		  if (!text_box->selection_active)
		    string_erase(text_box->text, text_box->cursor_pos);
		  else
		    erase_selection(text_box);
		  text_box->selection_active = false;
		}
	      else if (event->key.sym == BKS_LEFT && text_box->cursor_pos > 0)
		{
		  text_box->cursor_pos -= 1;
		  text_box->selection_active = false;
		}
	      else if (event->key.sym == BKS_RIGHT && text_box->cursor_pos < text_box->text->str_len)
		{
		  text_box->cursor_pos += 1;
		  text_box->selection_active = false;
		}
	      else if (event->key.sym == BKS_DOWN)
		{
		  text_box->cursor_pos += text_box->max_letter_on_line;
		  if (text_box->cursor_pos > text_box->text->str_len)
		    text_box->cursor_pos = text_box->text->str_len;
		  text_box->selection_active = false;
		}
	      else if (event->key.sym == BKS_UP)
		{
		  text_box->cursor_pos -= text_box->max_letter_on_line;
		  if (text_box->cursor_pos < 0)
		    text_box->cursor_pos = 0;
		  text_box->selection_active = false;
		}
	    }
	  else if (event->key.shift && !event->key.alt && !event->key.control && !event->key.system)
	    {
	      if (event->key.sym == BKS_RIGHT || event->key.sym == BKS_LEFT || event->key.sym == BKS_UP || event->key.sym == BKS_DOWN)
		{
		  if (!text_box->selection_active)
		    {
		      text_box->selection_active = true;
		      text_box->selected_area.start = text_box->cursor_pos;
		    }
		  if (event->key.sym == BKS_RIGHT && text_box->cursor_pos < text_box->text->str_len)
		    text_box->cursor_pos += 1;
		  else if (event->key.sym == BKS_LEFT && text_box->cursor_pos > 0)
		      text_box->cursor_pos -= 1;
		  else if (event->key.sym == BKS_UP && text_box->cursor_pos > 0)
		    {
		      text_box->cursor_pos -= text_box->max_letter_on_line;
		      if (text_box->cursor_pos < 0)
			text_box->cursor_pos = 0;
		    }
		  else if (event->key.sym == BKS_DOWN && text_box->cursor_pos < text_box->text->str_len)
		    {
		      text_box->cursor_pos += text_box->max_letter_on_line;
		      if (text_box->cursor_pos > text_box->text->str_len)
			text_box->cursor_pos = text_box->text->str_len;
		    }
		  text_box->selected_area.end = text_box->cursor_pos;
		}
	    }
	  else if (event->key.control && !event->key.alt && !event->key.shift && !event->key.system)
	    {
	      if (text_box->selection_active)
		{
		  if (event->key.sym == BKS_C)
		    copy_selection(text_box);
		  else if (event->key.sym == BKS_X)
		    cut_selection(text_box);
		  else if (event->key.sym == BKS_V)
		    {
		      erase_selection(text_box);
		      paste(text_box);
		    }
		}
	      else if (event->key.sym == BKS_V)
		paste(text_box);
	      text_box->selection_active = false;
	    }
	}
    }
}
