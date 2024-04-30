#include		"text_box.h"

void			paste(t_text_box		*box)
{
  int			i;

  i = 0;
  while (i < box->copy->str_len)
    {
      string_insert(box->text, box->cursor_pos, string_get_char(box->copy, i));
      i += 1;
      box->cursor_pos += 1;
    }
}
