#include       	"timer.h"

t_timer         *efnew_timer(t_timer_settings	*settings)
{
  t_timer	*time;

  if ((time = bunny_malloc(sizeof(t_timer))) == NULL)
    {
      perror(" bunny_malloc new_timer");
      return (NULL);
    }
  time->name = settings->name;
  time->last_time = bunny_get_current_time() * 1000;
  time->delai = settings->delai;
  time->functions = settings->functions;
}
