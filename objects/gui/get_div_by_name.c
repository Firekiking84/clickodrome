#include		"gui.h"

#include		<string.h>

t_div			*get_div_by_name(t_gui		*gui,
					 const char	*div_name)
{
  t_div			*target_div;
  int			i;

  i = 0;
  target_div = NULL;
  while (i < gui->divs->data_count && !(target_div != NULL && strcmp(div_name, target_div->name) == 0))
    {
      target_div = efvector_ptr_get(gui->divs, i);
      i += 1;
    }
  if (i == gui->divs->data_count)
    return(NULL);
  return(target_div);
}
