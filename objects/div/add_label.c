#include "div.h"

void			efadd_label_div(t_div			*div,
					t_label_settings	*settings)
{
  efvector_push(div->labels, efnew_label(settings));
}
