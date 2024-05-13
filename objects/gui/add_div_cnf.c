/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:42:09 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	        "gui.h"

int			efadd_div_cnf(t_bunny_configuration	*cnf,
				      t_bunny_configuration	*div,
				      t_gui			*gui)
{
  t_bunny_configuration	*components;
  t_div			*tdiv;
  int			i;

  while (div != bunny_configuration_end(cnf))
    {
      tdiv = efget_div_cnf(cnf, gui);
      efvector_ptr_push(gui->divs, tdiv);
      i = 0;
      while (bunny_configuration_getf(div, &components, "components[%d]", i))
	{
	  eftype_func(components,gui,i);
	  i += 1;
	}
      div = bunny_configuration_next(div);
    }
  return(1);
}
