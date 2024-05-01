#include "gui.h"
void			efadd_button_gui(t_gui			*gui,
					 t_button_settings	*settings)
{
  size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_button_div(&efvector_at(gui->divs, count, t_div), settings);
      count++;
    }
}
