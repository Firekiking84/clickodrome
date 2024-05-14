/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:44:19 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

t_bunny_position	efget_pos_cnf(t_bunny_configuration *cnf)
{
  t_bunny_position	pos;

  if (!cnf ||
      !bunny_configuration_getf(cnf, &pos.x, "pos[0]") ||
      !bunny_configuration_getf(cnf, &pos.y, "pos[1]"))
    {
      pos.x = -1;
      pos.y = -1;
      return (pos);
    };
  return(pos);
}
