#include "gui.h"

t_bunny_color efget_color_cnf(t_bunny_configuration *cnf,char *name)
{
  t_bunny_color color;
  int col1;
  int col2;
  int col3;
  bunny_configuration_getf(cnf,&col1,"components.%s[0]",name);
  bunny_configuration_getf(cnf,&col2,"components.%s[1]",name);
  bunny_configuration_getf(cnf,&col3,"components.%s[2]",name);
  color.full = col1*col2*col3;
  return (color);
}
