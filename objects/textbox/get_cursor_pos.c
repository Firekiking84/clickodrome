#include		"text_box.h"

int			get_cursor_pos(int				x,
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
