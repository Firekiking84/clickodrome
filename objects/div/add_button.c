#include "div.h"

void			efadd_button_div(t_div				*div,
					 t_button_settings		*settings)
{
  efvector_push(div->buttons, efnew_button(settings));
}
