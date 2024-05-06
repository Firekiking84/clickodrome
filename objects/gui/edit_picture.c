#include		"gui.h"

void			efedit_picture_gui(t_gui				*gui,
					  const char			*div_name,
					  t_picture_settings const	*edit)
{
  t_div			*target_div;

  target_div = get_div_by_name(gui, div_name);
  if (target_div)
    efedit_picture_div(target_div, edit);
}
