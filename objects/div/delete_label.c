#include	"gui.h"

bool		efdelete_label_div(t_div	*div,
				   const char	*elem_name)
{
  t_label	*label;
  size_t	i;

  i = 0;
  while (i < div->labels->data_count)
    {
      label = efvector_ptr_get(div->labels, i);
      if (strcmp(label->name, elem_name) == 0)
	{
	  efdelete_label(label);
	  efvector_ptr_erase(div->labels, i);
	  return(true);
	}
      i += 1;
    }
  return(false);
}

