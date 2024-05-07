#include		"div.h"

#include		<string.h>

static t_picture		*get_picture_by_name(t_vector			*pictures,
						     const char			*name)
{
  t_picture		*target;
  int			i;

  i = 0;
  target = NULL;
  while (i < pictures->data_count && !(target != NULL && strcmp(name, target->name) == 0))
    {
      target = efvector_ptr_get(pictures, i);
      i += 1;
    }
  if (i == pictures->data_count)
    return(NULL);
  return(target);
}

void			efedit_picture_div(t_div				*div,
					  t_picture_settings const	*edit)
{
  t_picture		*target;

  target = get_picture_by_name(div->pictures, edit->name);
  if (target)
    edit_picture(target, edit);
}
