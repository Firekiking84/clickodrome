#include		"gui.h"

void			efedit_timer_gui(t_gui				*gui,
					  const char			*div_name,
					  t_timer_settings		*edit)
{
  t_div			*target_div;

  target_div = get_div_by_name(gui, div_name);
  if (target_div)
    efedit_timer_div(target_div, edit);
}
