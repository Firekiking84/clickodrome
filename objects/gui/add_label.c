#include "gui.h"

void			efadd_label_gui(t_gui			*gui,
					t_label_settings	*settings)
{
    size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_label_div(&efvector_at(gui->divs, count, t_div), settings);
      count++;
    }
}
