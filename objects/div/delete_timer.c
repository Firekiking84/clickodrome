#include	"gui.h"

bool		efdelete_timer_div(t_div	*div,
				   const char	*elem_name)
{
  size_t	i;
  t_timer	*timer;

  i = 0;
  while (i < div->timers)
    {
      timer = efvector_ptr_get(div->timers, i);
      if (strcmp(timer->name, elem_name) == 0)
	{
	  efdelete_timer(timer);
	  efvector_ptr_erase(div->timers, i);
	  return(true);
	}
      i += 1;
    }
  return(false);
}

