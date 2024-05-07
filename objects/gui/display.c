#include		"gui.h"

void			efdisplay_gui(t_gui			*gui,
				      t_bunny_zpixelarray	*px)
{
  size_t count;

  count = 0;
  while (count < gui->divs->data_count)
    {
      efdisplay_div(&efvector_at(gui->divs, count, t_div), px);
      count++;
    }
}
