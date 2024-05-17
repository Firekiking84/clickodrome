#include	"gui.h"

bool		efdelete_picture_div(t_div	*div,
				     const char	*elem_name)
{
  size_t	i;
  t_picture	*picture;

  i = 0;
  while (i < div->pictures->data_count)
    {
      picture = efvector_ptr_get(div->pictures, i);
      if (strcmp(picture->name, elem_name) == 0)
	{
	  efdelete_picture(picture);
	  efvector_ptr_erase(div->pictures, i);
	  return(true);
	}
      i += 1;
    }
  return(false);
}
