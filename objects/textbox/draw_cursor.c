#include		"text_box.h"

void			draw_cursor(t_text_box			*text_box,
				    t_bunny_position		draw_pos,
				    t_bunny_pixelarray		*px)
{
  t_bunny_color		cursor_color;
  t_bunny_position	end_pos;
  double		cur_time;
  double		diff_time;

  cur_time = bunny_get_current_time();
  diff_time = cur_time - text_box->time_cursor_blink;
  if (diff_time > 1)
    text_box->time_cursor_blink = cur_time;
  else if  (diff_time < 0.75)
    {
      end_pos.x = draw_pos.x + 1;
      end_pos.y = draw_pos.y + text_box->size_font.y;
      cursor_color.full = text_box->font_color->full;
      draw_rectangle(px, &draw_pos, &end_pos, &cursor_color);
    }
}
