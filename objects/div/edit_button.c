#include		"div.h"

#include		<string.h>

static t_button		*get_button_by_name(t_vector			*buttons,
					    const char			*name)
{
  t_button		*target;
  int			i;

  i = 0;
  target = NULL;
  while (i < buttons->data_count && !(target != NULL && strcmp(name, target->name) == 0))
    {
      target = efvector_ptr_get(buttons, i);
      i += 1;
    }
  if (i == buttons->data_count)
    return(NULL);
  return(target);
}

void			efedit_button_div(t_div				*div,
					  t_button_settings const	*edit)
{
  t_button		*target;

  target = get_button_by_name(div->buttons, edit->name);
  if (target)
    edit_button(target, edit);
}
