#include		"timer.h"

void            efrefresh_timer(t_timer                         *timer)
{
  double	time;
  size_t	i;

  i = 0;
  time = bunny_get_current_time() * 1000;
  if (time - timer->delay >= timer->last_time)
    {
      while (i < timer->functions->data_count)
	{
	  ((void (*)(void))efvector_ptr_get(timer->functions, 0))();
	  i++;
	}
      timer->last_time = time;
    }
}
