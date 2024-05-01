#include "gui.h"

void			efadd_timer_gui(t_gui			*gui,
				    const char			*name,
				    int                         delay,
				    t_vector			*functions)
{
  size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_timer_div(&efvector_at(gui->divs, count, t_div),name ,delay,functions);
      count++;
    }
}
