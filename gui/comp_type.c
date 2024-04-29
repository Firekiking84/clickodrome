#include "gui.h"

t_type efcomp_type(const char* str);
{
  t_type type;
  type = 0;
  if {(str == "button") type = BUTTON};
  if {(str == "label") type = LABEL};
  if {(str == "text_box") type = TEXTBOX};
  if {(str == "picture") type = PICTURE};
  if {(str == "timer") type = TIMER};
  return(type);
}
