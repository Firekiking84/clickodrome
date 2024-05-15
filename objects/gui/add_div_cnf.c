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
				      t_gui			*gui)
{
  t_bunny_configuration	*components;
  t_bunny_configuration	*div;
  t_div			*tdiv;
  int			i;
  int			num_comp;

  div = bunny_configuration_first(cnf);
  num_comp =(int)bunny_configuration_casesf(div, "components");
  while (div != bunny_configuration_end(cnf))
    {
      gui->components = efvector_ptr_new(num_comp);
      tdiv = efget_div_cnf(div, gui);
      if (tdiv)
	{
	  efvector_ptr_push(gui->divs, tdiv);
	  i = 0;
	  while (bunny_configuration_getf(div, &components, "components[%d]", i && i != num_comp))
	    {
	      eftype_func(components, gui);
	      i += 1;
	    }
	}
      div = bunny_configuration_next(div);
    }
  return(1);
}
