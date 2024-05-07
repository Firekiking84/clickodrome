#include "button.h"

void			efdisplay_button(t_button		*button,
					 t_bunny_pixelarray	*px)
{
  t_text_settings		set;

  set.pix = px;
  set.font = button->font;
  set.font_size = button->font_size;
  set.pos = button->pos;
  set.txt = button->text;
  set.font_color = button->font_color;
  if ( button->bg != NULL)
    draw_rectangle(px ,&button->pos ,&button->pos ,button->hover_color);
  eftext(&set);
}
