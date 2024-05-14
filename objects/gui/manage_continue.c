#include		"gui.h"

t_bunny_response	manage_continue(t_gui		*gui)
{
  if (gui->is_end)
    return(EXIT_ON_SUCCESS);
  else
    return(GO_ON);
}
