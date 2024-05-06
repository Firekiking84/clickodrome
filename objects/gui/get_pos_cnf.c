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

  bunny_configuration_getf(cnf,&pos.x,"components.pos[0]");
  bunny_configuration_getf(cnf,&pos.y,"components.pos[1]");
  if (cnf == NULL)
    {
      pos.x = 400;
      pos.y = 400;
      return (pos);
    }
  return(pos);
}
