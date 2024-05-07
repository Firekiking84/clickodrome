/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:44:59 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

t_gui			*efnew_gui(const char	*file)
{
  t_bunny_configuration	*cnf;
  t_bunny_configuration	*div;
  t_gui			*gui;

  cnf = bunny_open_configuration(file, NULL);
  if (cnf == NULL)
    {
      puts("Failed to open file");
      return(NULL);
    }
  gui = bunny_malloc(sizeof(t_gui));
  if (!gui)
    return(NULL);
  gui->components = efvector_ptr_new((int)bunny_configuration_casesf(cnf, "components"));
  gui->components = efvector_ptr_new((int)bunny_configuration_childrenf(cnf, "[]"));
  div = bunny_configuration_first(cnf);
  efadd_div_cnf(cnf, div, gui);
  return (gui);
}

