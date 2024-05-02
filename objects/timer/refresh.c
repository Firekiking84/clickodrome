#include		"timer.h"

void            efrefresh_timer(t_timer                         *timer)
{
  double	time;
  size_t	i;

  time = bunny_get_current_time() * 1000;
  if (time - timer->delai >= timer->last_time)
    {
      while (i < timer->functions->data_count)
	{
	  efvector_funcptr_at(timer->functions, i, void(*)(void))();
	  i++;
	}
      timer->last_time = time;
    }
}
