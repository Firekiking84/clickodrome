#include		"text_box.h"

#include		<stdlib.h>
#include		<string.h>

t_text_box		*efnew_text_box(t_zposition		pos,
					t_bunny_size		size,
					const char		*name,
					t_bunny_color		font_color,
					t_bunny_color		*bg,
					t_vector		*functions)
{
  t_text_box		*new_text_box;
  size_t		i;
  size_t		func_ptr;

  new_text_box = malloc(sizeof(t_text_box));
  if (!new_text_box)
    return(NULL);
  new_text_box->pos = pos;
  new_text_box->size = size;
  new_text_box->has_focus = false;
  new_text_box->pressed_in = false;
  new_text_box->cursor_pos = 0;
  new_text_box->selection_active = false;
  new_text_box->copy = string_new();
  new_text_box->size_font.x = 10;
  new_text_box->size_font.y = 14;
  new_text_box->max_letter_on_line = new_text_box->size.x / (new_text_box->size_font.x + 2);
  new_text_box->max_nb_lines = new_text_box->size.y / (new_text_box->size_font.y + 2);
  new_text_box->max_letter = new_text_box->max_letter_on_line * new_text_box->max_nb_lines;
  new_text_box->font = bunny_load_pixelarray("/home/users/keryan.houssin/work/projet/Clickodrome/res/font.png");
  new_text_box->font->clipable.clip_width = new_text_box->size_font.x;
  new_text_box->font->clipable.clip_height = new_text_box->size_font.y;
  new_text_box->name = strdup(name);
  new_text_box->text = string_new();
  new_text_box->font_color = font_color;
  new_text_box->time_cursor_blink = bunny_get_current_time();
  if (!bg)
    new_text_box->bg = NULL;
  else
    {
      new_text_box->bg = malloc(sizeof(t_bunny_color));
      if (!new_text_box->bg)
	return(NULL);
      new_text_box->bg->full = bg->full;
    }
  new_text_box->functions = efvector_new(size_t, functions->data_count);
  i = 0;
  while (i < functions->data_count)
    {
      func_ptr = efvector_at(functions, i, size_t);
      efvector_push(new_text_box->functions, &func_ptr);
      i += 1;
    }
  return(new_text_box);
}
