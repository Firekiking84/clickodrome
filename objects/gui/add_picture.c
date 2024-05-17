#include		"gui.h"

#include		<stdio.h>

void			efadd_picture_gui(t_gui				*gui,
					  char const			*div_name,
					  t_picture_settings		*add)
{
  size_t		i;
  t_div			*div;

  i = 0;
  while (i < gui->divs->data_count)
    {
      div = efvector_ptr_get(gui->divs, i);
      if (strcmp(div->name, div_name) == 0)
	{
	  efadd_picture_div(div, add);
	  return;
	}
      i += 1;
    }
  dprintf(2, "Cannot find the div : %s\n", div_name);
}
