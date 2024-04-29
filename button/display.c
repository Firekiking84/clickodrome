#include "button.h"
void			efdisplay_button(t_button		*button,
					 t_bunny_zpixelarray	*px)
{
  if ( button->bg != NULL)
    draw_rectangle(px ,button->pos ,button->pos ,&button->font_color);
  eftext(px ,font ,button->pos ,button->text ,button->font_color);
}
