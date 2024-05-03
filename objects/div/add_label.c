#include	"div.h"

t_label		*efadd_label_div(t_div			*div,
				 t_label_settings	*settings)
{
  t_label	*label;

  if (!efcheck_pos_new_component(div->pos, div->end_pos, &settings->pos, &settings->size))
    return(NULL);
  label = efnew_label(settings);
  if (!label)
    return(NULL);
  efvector_ptr_push(div->labels, label);
  return (label);
}
