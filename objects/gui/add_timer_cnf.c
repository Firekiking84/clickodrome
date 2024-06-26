/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:43:01 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

#include		<string.h>

static int		init_timer_settings(t_bunny_configuration	*cnf,
					    t_gui			*gui,
					    t_timer_settings		*settings)
{
  const char		*tmp;
  int			delay;

  settings->gui = gui;
  bunny_configuration_getf(cnf, &tmp, "name");
  settings->name = strdup(tmp);
  if (!settings->name)
    return(-1);
  if (!bunny_configuration_getf_int(cnf, &delay, "delay"))
    delay = 1;
  settings->delay = (size_t)delay;
  if (!settings->delay)
    {
      bunny_free((char *)settings->name);
      return(-1);
    }
  settings->functions = efget_functions(cnf, gui);
  if (!settings->functions)
    {
      bunny_free((char *)settings->name);
      return(-1);
    }
  return(0);
}

int			efadd_timer_cnf(t_bunny_configuration		*cnf,
					t_gui				*gui)
{
  t_timer_settings	settings;

  if (init_timer_settings(cnf, gui, &settings) == -1)
    return(-1);
  efadd_timer_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  return(0);
}
