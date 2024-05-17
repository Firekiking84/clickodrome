#include		"gui.h"

void			efedit_button_gui(t_gui				*gui,
					  const char			*div_name,
					  t_button_settings		*edit)
{
  t_div			*target_div;

  target_div = get_div_by_name(gui, div_name);
  if (target_div)
    efedit_button_div(target_div, edit);
}
