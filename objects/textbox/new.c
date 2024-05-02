/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 30/04/2024 15:59:08 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"text_box.h"

#include		<stdlib.h>
#include		<string.h>

static int		allocation_assign(t_text_box		*box,
					  t_textbox_settings	*settings)
{
  box->font = bunny_load_pixelarray("./font.png");
  if (!box->font)
    return(-1);
  if (!settings->bg)
    box->bg = NULL;
  else
    {
      box->bg =  bunny_malloc(sizeof(t_bunny_color));
      if (!box->bg)
	{
	  bunny_delete_clipable(&box->font->clipable);
	  return(-1);
	}
      box->bg->full = settings->bg->full;
    }
  box->functions = efvector_new_vector(settings->functions);
  if (!box->functions)
    {
      bunny_delete_clipable(&box->font->clipable);
      free(box->bg);
      return(-1);
    }
  return(0);
}

static int		assign_settings(t_text_box		*box,
					t_textbox_settings	*settings)
{
  if (allocation_assign(box, settings) == -1)
    return(-1);
  box->pos = settings->pos;
  box->size = settings->size;
  box->name = settings->name;
  box->font_color = settings->font_color;
  box->size_font.x = 10;
  box->size_font.y = 14;
  return(0);
}

static void		init_textbox_values(t_text_box		*box)
{
  box->has_focus = false;
  box->pressed_in = false;
  box->cursor_pos = 0;
  box->selection_active = false;
  box->text = string_new();
  box->copy = string_new();
  box->time_cursor_blink = bunny_get_current_time();
}

static void		calcul_textbox_values(t_text_box	*box)
{
  box->max_letter_on_line = box->size.x / (box->size_font.x + 2);
  box->max_nb_lines = box->size.y / (box->size_font.y + 2);
  box->max_letter = box->max_letter_on_line * box->max_nb_lines;
  box->font->clipable.clip_width = box->size_font.x;
  box->font->clipable.clip_height = box->size_font.y;
}

t_text_box		*efnew_text_box(t_textbox_settings	*settings)
{
  t_text_box		*new_text_box;

  new_text_box =  bunny_malloc(sizeof(t_text_box));
  if (!new_text_box)
    return(NULL);
  if (assign_settings(new_text_box, settings) == -1)
    {
      free(new_text_box);
      return(NULL);
    }
  init_textbox_values(new_text_box);
  calcul_textbox_values(new_text_box);
  return(new_text_box);
}
