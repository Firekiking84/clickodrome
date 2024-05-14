#include	"timer.h"

t_timer         *efnew_timer(t_timer_settings	*settings)
{
  t_timer	*time;

  if ((time = bunny_malloc(sizeof(t_timer))) == NULL)
    {
      perror(" bunny_malloc new_timer");
      return (NULL);
    }
  time->gui = settings->gui;
  time->name = settings->name;
  time->last_time = bunny_get_current_time() * 1000;
  if (settings->delay < 0)
    {
      dprintf(2, "Wrong delay value. Set to default(1)");
      time->delay = 1;
    }
  else
    time->delay = settings->delay;
  time->lib = settings->lib;
  time->functions = settings->functions;
  return (time);
}
