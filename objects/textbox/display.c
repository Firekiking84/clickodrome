/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 30/04/2024 15:59:35 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"text_box.h"

static void		increment_display_values(t_text_box		*text_box,
						 t_display_values	*val)
{
  val->n_letter += 1;
  if (val->n_letter >= text_box->max_letter_on_line)
    {
      val->n_letter = 0;
      val->n_line += 1;
    }
  val->i += 1;
}

static bool		is_selected_area(t_text_box		*text_box,
					 int			i)
{
  if (!text_box->selection_active)
    return(false);
  if (text_box->selected_area.start > text_box->selected_area.end)
    {
      if (i < text_box->selected_area.start && i >= text_box->selected_area.end)
	return(true);
    }
  else
    if (i >= text_box->selected_area.start && i < text_box->selected_area.end)
      return(true);
  return(false);
}

static void		init_display_values(t_text_box		*box,
					    t_display_values	*val)
{
 if (box->text->str_len < box->max_letter)
    val->start = 0;
  else
    {
      val->start = box->text->str_len - box->max_letter;
      if (val->start > box->cursor_pos)
	val->start = box->cursor_pos;
    }
  val->n_line = 0;
  val->n_letter = 0;
  val->i = val->start;
}

void			efdisplay_text_box(t_text_box		*text_box,
					   t_bunny_zpixelarray	*px)
{
  t_zposition		draw_pos;
  t_display_values	val;

  draw_bg(text_box, px);
  draw_pos.z = text_box->pos.z;
  init_display_values(text_box, &val);
  while (val.i < text_box->text->str_len && (val.i - val.start) < text_box->max_letter)
    {
      draw_pos.x = text_box->pos.x + (val.n_letter * (text_box->size_font.x + 2));
      draw_pos.y = text_box->pos.y + 1 + (val.n_line * text_box->size_font.y);
      if (is_selected_area(text_box, val.i))
	draw_selected_area(text_box, draw_pos, px);
      text_box->font->clipable.clip_x_position = string_get_char(text_box->text, val.i) * text_box->size_font.x;
      blit(px, text_box->font, &draw_pos, text_box->font_color);
      if (val.i == text_box->cursor_pos)
	draw_cursor(text_box, draw_pos, px);
      increment_display_values(text_box, &val);
    }
  if (val.i == text_box->cursor_pos)
    {
      draw_pos.x = text_box->pos.x + (val.n_letter * (text_box->size_font.x + 2));
      draw_pos.y = text_box->pos.y + 1 + (val.n_line * text_box->size_font.y);
      draw_cursor(text_box, draw_pos, px);
    }
}
