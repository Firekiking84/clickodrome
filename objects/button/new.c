#include		"button.h"

t_button		*efnew_button(t_button_settings *set)

{
  t_button		*button;

  if ((button = bunny_malloc (sizeof(button))) == NULL)
    return(NULL);
  button->pos = set->pos;
  button->size = set->size;
  button->text = set->text;
  button->focus = false;
  button->in_button = false;
  button->name = set->name;
  button->hover_color = set->hover_color;
  button->font_size = set->font_size;
  button->font = bunny_load_pixelarray(set->font);
  if (!button->font)
    return(NULL);
  button->font_color = set->font_color;
  button->bg = set->bg;
  button->functions = set->functions;
  return(button);
}
