#include "gui.h"

void			efadd_picture_gui(t_gui			*gui,
					  t_picture_settings	*settings)
{
  size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_picture_div(&efvector_at(gui->divs, count, t_div), settings);
      count++;
    }
}
