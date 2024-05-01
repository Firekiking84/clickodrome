#include "gui.h"

t_type efcomp_type(const char* str)
{
  t_type type;
  type = 0;
  if (strcmp(str,"button"))
    {
      type = BUTTON;
    }
  if (strcmp(str,"label"))
    {
      type = LABEL;
    }
  if (strcmp(str,"text_box"))
    {
      type = TEXTBOX;
    }
  if (strcmp(str,"picture"))
    {
      type = PICTURE;
    }
  if (strcmp(str,"timer"))
    {
      type = TIMER;
    }
  return(type);
}
