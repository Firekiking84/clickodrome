/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:43:50 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

t_div			*efget_div_cnf(t_bunny_configuration *cnf)
{
  t_div			*tdiv;
  const char		*divname;
  t_bunny_size		size;
  t_bunny_position	pos;

  bunny_configuration_getf(cnf, &divname, "[]");
  pos = efget_posz_cnf(cnf);
  size = efget_size_cnf(cnf, "components.size");
  tdiv = efnew_div(divname, pos, size);
  return(tdiv);
}
