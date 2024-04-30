#include "gui.h"

void efdelete_gui(t_gui *gui)
{
  size_t count;
  count = 0;

  efvector_delete(gui->libs);
  efvector_delete(gui->components);
  while (count < gui->divs->data_count)
    {
      efdelete_div(&efvector_at(gui->divs, count, t_div));
      count++;
    }
}
