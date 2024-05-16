#include	"gui.h"

bool		efdelete_button_div(t_div	*div,
				    const char	*elem_name)
{
  size_t	i;
  t_button	*button;

  i = 0;
  while (i < div->buttons->data_count)
    {
      button = efvector_ptr_get(div->buttons, i);
      if (strcmp(button->name, elem_name) == 0)
	{
	  efdelete_button(button);
	  efvector_ptr_erase(div->buttons, i);
	  return(true);
	}
      i += 1;
    }
  return(false);
}

