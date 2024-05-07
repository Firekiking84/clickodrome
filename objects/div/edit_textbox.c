#include		"div.h"

#include		<string.h>

static t_text_box		*get_textbox_by_name(t_vector_ptr		*textboxs,
						     const char			*name)
{
  t_text_box		*target;
  size_t 	        i;

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
  t_text_box		*target;

  target = get_textbox_by_name(div->text_boxes, edit->name);
  if (target)
    efedit_textbox(target, edit);
}
