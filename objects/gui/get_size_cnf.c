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

t_bunny_size	efget_size_cnf(t_bunny_configuration	*cnf,
			       char const		*elem)
{
  t_bunny_size	size;

  if (!bunny_configuration_getf(cnf, &size.x, "%s[0]", elem) ||
      !bunny_configuration_getf(cnf, &size.y, "%s[1]", elem))
    {
      bunny_perror("Cannot get size !");
      size.x = 0;
      size.y = 0;
    }
  return(size);
}
