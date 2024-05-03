#include "div.h"

t_button			*efadd_button_div(t_div				*div,
						  t_button_settings		*settings)
{
  t_button	 *button;

  button = efnew_button(settings);
  if (!button)
    return(NULL);
  efvector_ptr_push(div->buttons, button);
  return (button);
}
