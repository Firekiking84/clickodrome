#include		"text_box.h"

static void	        manage_key_selection(t_text_box			*text_box,
					     const t_bunny_event	*event)
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


void			manage_shift_key(t_text_box			*text_box,
					 const t_bunny_event		*event)
{
  manage_key_selection(text_box, event);
}
