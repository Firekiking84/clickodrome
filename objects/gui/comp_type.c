#include	"gui.h"

t_type		efcomp_type(const char*		str)
{
  t_type	type;

  type = 0;
  if (strcmp(str,"button") == 0)
    type = BUTTON;
  else if (strcmp(str,"label") == 0)
    type = LABEL;
  else if (strcmp(str,"text_box") == 0)
    type = TEXTBOX;
  else if (strcmp(str,"picture") == 0)
    type = PICTURE;
  else if (strcmp(str,"timer") == 0)
    type = TIMER;
  return(type);
}