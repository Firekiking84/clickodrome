#include "gui.h"

t_div *efget_div_cnf(t_bunny_configuration *cnf)
{
  t_div *tdiv;
  const char *divname;
  t_bunny_size size;
  t_zposition pos;

  bunny_configuration_getf(cnf, &divname, "[]");
  pos = efget_posz_cnf(cnf);
  size = efget_size_cnf(cnf);
  tdiv = efnew_div(divname, &pos, size);
  return(tdiv);
}
