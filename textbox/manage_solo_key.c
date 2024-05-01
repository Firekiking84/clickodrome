#include		"text_box.h"

static bool		manage_exec(t_text_box				*text_box,
				    const t_bunny_event			*event)
{
  int			i;
  void			(*func_ptr)(const char *);

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
      return(true);
    }
  return(false);
}

static bool		manage_text_edit(t_text_box			*text_box,
					 const t_bunny_event		*event)
{
  if (event->key.sym == BKS_BACKSPACE && text_box->cursor_pos > 0)
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
  else
    return(false);
  return(true);
}

static void		manage_move_cursor(t_text_box			*text_box,
					   const t_bunny_event		*event)
{
  if (event->key.sym == BKS_LEFT && text_box->cursor_pos > 0)
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

void			manage_solo_key(t_text_box			*text_box,
					const t_bunny_event		*event)
{
  if (manage_exec(text_box, event))
    return;
  else if (manage_text_edit(text_box, event))
    return;
  manage_move_cursor(text_box, event);
}
