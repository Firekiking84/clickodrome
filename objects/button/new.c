#include		"button.h"

t_button		*efnew_button(t_button_settings *set)

{
  t_button		*button;

  if ((button = bunny_malloc(sizeof(button))) == NULL)
    return(NULL);
  button->gui = set->gui;
  button->pos = set->pos;
  button->pos_end.x = set->pos.x + set->size.x;
  button->pos_end.y = set->pos.y + set->size.y;
  button->size = set->size;
  button->text = set->text;
  button->focus = false;
  button->in_button = false;
  button->is_hover = false;
  button->name = set->name;
  button->font = bunny_load_pixelarray(set->font);
  if (!button->font)
    return(NULL);
  button->click_color = set->click_color;
  button->hover_color = set->hover_color;
  button->font_size = set->font_size;
  button->font_color = set->font_color;
  button->bg = set->bg;
  button->lib = set->lib;
  button->functions = set->functions;
  return(button);
}
