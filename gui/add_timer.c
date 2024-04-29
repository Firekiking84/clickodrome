#include "gui.h"

void			efadd_timer_gui(t_gui			*gui,
				    const char			*name,
				    t_vector			*functions)
{
  size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_timer_div(efvecteur_at(gui->divs, count, t_div),name ,functions);
      count++;
    }
}
