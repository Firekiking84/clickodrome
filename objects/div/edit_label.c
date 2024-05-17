#include		"div.h"

#include		<string.h>

static t_label		*get_label_by_name(t_vector_ptr			*labels,
					    const char			*name)
{
  t_label		*target;
  size_t		i;

  i = 0;
  target = NULL;
  while (i < labels->data_count && !(target != NULL && strcmp(name, target->name) == 0))
    {
      target = efvector_ptr_get(labels, i);
      i += 1;
    }
  if (i == labels->data_count && target && strcmp(name, target->name) != 0)
    return(NULL);
  return(target);
}

void			efedit_label_div(t_div				*div,
					 t_label_settings const		*edit)
{
  t_label		*target;

  target = get_label_by_name(div->labels, edit->name);
  if (target)
    efedit_label(target, edit);
}
