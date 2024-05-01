#include "gui.h"

t_bunny_size efget_size_cnf(t_bunny_configuration *cnf)
{
  t_bunny_size size;
  bunny_configuration_getf(cnf,&size.x,"components.size[0]");
  bunny_configuration_getf(cnf,&size.y,"components.size[1]");
  return(size);
}
