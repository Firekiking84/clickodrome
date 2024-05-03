#include "div.h"

t_label			*efadd_label_div(t_div			*div,
					t_label_settings	*settings)
{
  t_label	 *label;

  label = efnew_label(settings);
  if (!label)
    return(NULL);
  efvector_ptr_push(div->labels, label);
  return (label);
}
