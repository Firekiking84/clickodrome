#include		"gui.h"

#include		<stdio.h>

void			efdelete_elem_gui(t_gui			*gui,
					  const char		*div_name,
					  const char		*elem_name)
{
  size_t		i;
  t_div			*div;

  i = 0;
  while (i < gui->divs->data_count)
    {
      div = efvector_ptr_get(gui->divs, i);
      if (strcmp(div->name, div_name) == 0)
	{
	  efdelete_elem_div(div, elem_name);
	  return;
	}
      i += 1;
    }
  dprintf(2, "Cannot find div : %s\n", div_name);
}
