#include	"gui.h"

bool		efdelete_textbox_div(t_div	*div,
				     const char	*elem_name)
{
  size_t	i;
  t_text_box	*textbox;

  i = 0;
  while (i < div->text_boxes->data_count)
    {
      textbox = efvector_ptr_get(div->text_boxes, i);
      if (strcmp(textbox->name, elem_name) == 0)
	{
	  efdelete_text_box(textbox);
	  efvector_ptr_erase(div->text_boxes, i);
	  return(true);
	}
      i += 1;
    }
  return(false);
}

