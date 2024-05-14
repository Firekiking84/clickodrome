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
  t_gui			*gui;

  cnf = bunny_open_configuration(file, NULL);
  if (cnf == NULL)
    {
      bunny_perror("Failed to open file");
      return(NULL);
    }
  gui = bunny_malloc(sizeof(t_gui));
  if (!gui)
    return(NULL);
  gui->nb_input_components = 0;
  if (!bunny_configuration_getf(cnf, &gui->screen_size.x, "screen[0]"))
    {
      puts("Cannot get screen_size !");
      return(NULL);
    }
  if (!bunny_configuration_getf(cnf, &gui->screen_size.y, "screen[1]"))
    {
      puts("Cannot get screen_size !");
      return(NULL);
    }
  gui->components = efvector_ptr_new((int)bunny_configuration_casesf(cnf, "components"));
  gui->divs = efvector_ptr_new((int)bunny_configuration_childrenf(cnf, "[]"));
  gui->libs = efvector_ptr_new(0);
  gui->divs = efvector_ptr_new(0);
  gui->libs = efvector_ptr_new(0);
  gui->is_end = false;
  efadd_div_cnf(cnf, gui);
  return(gui);
}

