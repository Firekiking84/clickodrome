#include		"gui.h"
#include		"clickodrome.h"

void			efevent_gui(t_bunny_event const		*event,
				    void			*data)
{
  size_t		count ;
  t_program		*dataptr;

  dataptr = (t_program *)data;
  count = 0;
  while (count < dataptr->gui->divs->data_count)
    {
      efevents_div(efvector_ptr_get(dataptr->gui->divs, count) ,event);
      count++;
    }
}
