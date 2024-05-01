
#include "button.h"

void			efdisplay_button(t_button		*button,
					 t_bunny_zpixelarray	*px)
{
  if ( button->bg != NULL)
    draw_rectangle(px ,&button->pos ,&button->pos ,&button->hover_color);
  eftext(px ,px->px ,&button->pos ,button->text ,button->font_color);
}
