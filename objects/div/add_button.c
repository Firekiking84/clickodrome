#include	"div.h"

t_button	*efadd_button_div(t_div				*div,
				  t_button_settings		*settings)
{
  t_button	 *button;

  settings->lib = div->lib;
  if (!efcheck_pos_new_component(div, &settings->pos, &settings->size))
    return(NULL);
  button = efnew_button(settings);
  if (!button)
    return(NULL);
  efvector_ptr_push(div->buttons, button);
  return (button);
}
