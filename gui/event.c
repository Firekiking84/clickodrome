#include "gui.h"
void			efevent_gui(t_bunny_event const		*event,
				    void			*data)
{
  size_t count ;

  count = 0;
  while (count < data->gui->divs->data_count)
    {
      efevent_div(&efvector_at(data->gui->divs, count,t_div) ,event);
      count++;
    }
}
