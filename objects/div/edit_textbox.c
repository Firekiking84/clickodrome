#include		"div.h"

#include		<string.h>

static t_textbox		*get_textbox_by_name(t_vector			*textboxs,
						     const char			*name)
{
  t_textbox		*target;
  int			i;

  i = 0;
  target = NULL;
  while (i < textboxs->data_count && !(target != NULL && strcmp(name, target->name) == 0))
    {
      target = efvector_ptr_get(textboxs, i);
      i += 1;
    }
  if (i == textboxs->data_count)
    return(NULL);
  return(target);
}

void			efedit_textbox_div(t_div				*div,
					   t_textbox_settings const		*edit)
{
  t_textbox		*target;

  target = get_textbox_by_name(div->textboxs, edit->name);
  if (target)
    edit_textbox(target, edit);
}
