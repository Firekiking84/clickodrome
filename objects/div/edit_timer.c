#include		"div.h"

#include		<string.h>

static t_timer		*get_timer_by_name(t_vector_ptr			*timers,
					    const char			*name)
{
  t_timer		*target;
  size_t		i;

  i = 0;
  target = NULL;
  while (i < timers->data_count && !(target != NULL && strcmp(name, target->name) == 0))
    {
      target = efvector_ptr_get(timers, i);
      i += 1;
    }
  if (i == timers->data_count)
    return(NULL);
  return(target);
}

void			efedit_timer_div(t_div				*div,
					  t_timer_settings const	*edit)
{
  t_timer		*target;

  target = get_timer_by_name(div->timers, edit->name);
  if (target)
    efedit_timer(target, edit);
}
