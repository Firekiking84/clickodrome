
#include "button.h"
void			efdisplay_button(t_button		*button,
					 t_bunny_zpixelarray	*px)
{
  t_text_settings		set;

  if ( button->bg != NULL)
    draw_rectangle(px ,&button->pos ,&button->pos ,button->hover_color);
  eftext(&set);
}
