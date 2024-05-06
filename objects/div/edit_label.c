#include		"div.h"

#include		<string.h>

static t_label		*get_label_by_name(t_vector			*labels,
					    const char			*name)
{
  t_label		*target;
  int			i;

  i = 0;
  target = NULL;
  while (i < labels->data_count && !(target != NULL && strcmp(name, target->name) == 0))
    {
      target_div = efvector_ptr_get(labels, i);
      i += 1;
    }
  if (i == labels->data_count)
    return(NULL);
  return(target);
}

void			efedit_label_div(t_div				*div,
					  t_label_settings const	*edit)
{
  t_label		*target;

  target = get_label_by_name(div->labels, edit->name);
  if (target)
    edit_label(target, edit);
}
