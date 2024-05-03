#include "button.h"

void			efdelete_button(t_button		*button)
{
  free(button->text);
  free(button->name);
  free(button->hover_color);
  free(button->font_color);
  free(button->bg);
  bunny_delete_clipable(&button->font->clipable);
  efvector_ptr_delete(button->functions);
  free(button);
}
