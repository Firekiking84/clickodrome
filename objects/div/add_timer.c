#include		"div.h"

t_timer			*efadd_timer_div(t_div				*div,
					 t_timer_settings		*set)
{
  t_timer		*timer;

  timer = efnew_timer(set);
  if (!timer)
    return(NULL);
  efvector_ptr_push(div->timers, timer);
  return(timer);
}
