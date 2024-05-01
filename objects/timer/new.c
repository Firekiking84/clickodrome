#include		"timer.h"

t_timer         *efnew_timer(const char                         *name,
			     size_t	                        delai,
			     t_vector                           *functions)
{
  t_timer	*time;

  if ((time = malloc(sizeof(t_timer))) == NULL)
    {
      perror("malloc new_timer");
      return (NULL);
    }
  if ((time->name = malloc(strlen(name))) == NULL)
    {
      perror("malloc new_timer_name");
      return (NULL);
    }
  strcpy(time->name, name);
  time->last_time = bunny_get_current_time() * 1000;
  time->delai = delai;
  time->functions = functions;
}
