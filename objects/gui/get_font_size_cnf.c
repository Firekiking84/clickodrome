/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:44:06 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	"gui.h"

t_bunny_size	efget_size_cnf(t_bunny_configuration *cnf)
{
  t_bunny_size	size;

  bunny_configuration_getf(cnf,&size.x,"components.font[0]");
  bunny_configuration_getf(cnf,&size.y,"components.font[1]");
  return(size);
}
