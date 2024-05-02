#include		"timer.h"

void            efdelete_timer(t_timer                          *timer)
{
  if (timer == NULL)
    return ;
  free(timer->name);
  free(timer);
}
