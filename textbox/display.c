#include		"text_box.h"

static void		draw_bg(t_text_box			*text_box,
				t_bunny_zpixelarray		*px)
{
  t_zposition		end_pos;

  if (text_box->bg)
    {
      end_pos.z = text_box->pos.z;
      end_pos.x = text_box->pos.x + text_box->size.x;
      end_pos.y = text_box->pos.y + text_box->size.y;
      draw_rectangle(px, &text_box->pos, &end_pos, text_box->bg);
    }
}

static void		draw_cursor(t_text_box			*text_box,
				    t_zposition			draw_pos,
				    t_bunny_zpixelarray		*px)
{
  t_bunny_color		cursor_color;
  t_zposition		end_pos;
  double		cur_time;
  double		diff_time;

  cur_time = bunny_get_current_time();
  diff_time = cur_time - text_box->time_cursor_blink;
  if (diff_time > 1)
    text_box->time_cursor_blink = cur_time;
  else if  (diff_time < 0.75)
    {
      end_pos.z = draw_pos.z;
      end_pos.x = draw_pos.x + 1;
      end_pos.y = draw_pos.y + text_box->size_font.y;
      cursor_color.full = text_box->font_color.full;
      draw_rectangle(px, &draw_pos, &end_pos, &cursor_color);
    }
}

static void		increment_draw_values(t_text_box	*text_box,
					      int		*i,
					      int		*n_line,
					      int	        *n_letter)
{
  *n_letter += 1;
  if (*n_letter >= text_box->max_letter_on_line)
    {
      *n_letter = 0;
      *n_line += 1;
    }
  *i += 1;
}

void			efdisplay_text_box(t_text_box		*text_box,
					   t_bunny_zpixelarray	*px)
{
  t_zposition		draw_pos;
  int			start;
  int			i;
  int			n_line;
  int			n_letter;

  draw_bg(text_box, px);
  draw_pos.z = text_box->pos.z;
  if (text_box->text->str_len < text_box->max_letter)
    start = 0;
  else
    {
      start = text_box->text->str_len - text_box->max_letter;
      if (start > text_box->cursor_pos)
	start = text_box->cursor_pos;
    }
  n_line = 0;
  n_letter = 0;
  i = start;
  while (i < text_box->text->str_len && (i - start) < text_box->max_letter)
    {
      draw_pos.x = text_box->pos.x + (n_letter * (text_box->size_font.x + 2));
      draw_pos.y = text_box->pos.y + 1 + (n_line * text_box->size_font.y);
      text_box->font->clipable.clip_x_position = string_get_char(text_box->text, i) * text_box->size_font.x;
      blit(px, text_box->font, &draw_pos, &text_box->font_color);
      if (i == text_box->cursor_pos)
	{
	  draw_pos.x = text_box->pos.x + (n_letter * (text_box->size_font.x + 2));
	  draw_pos.y = text_box->pos.y + 1 + (n_line * text_box->size_font.y);
	  draw_cursor(text_box, draw_pos, px);
	}
      increment_draw_values(text_box, &i, &n_line, &n_letter);
    }
  if (i == text_box->cursor_pos)
    {
      draw_pos.x = text_box->pos.x + (n_letter * (text_box->size_font.x + 2));
      draw_pos.y = text_box->pos.y + 1 + (n_line * text_box->size_font.y);
      draw_cursor(text_box, draw_pos, px);
    }
}
