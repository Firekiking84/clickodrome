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

t_bunny_size	efget_size_cnf(t_bunny_configuration	*cnf)
{
  t_bunny_size	size;

  if (!bunny_configuration_getf(cnf, &size.x, "size[0]") ||
      !bunny_configuration_getf(cnf, &size.y, "size[1]"))
    {
      bunny_perror("Cannot get size !");
      size.x = 0;
      size.y = 0;
    }
  return(size);
}
