/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:42:20 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

static int		init_picture_settings(t_bunny_configuration	*cnf,
					      t_picture_settings	*settings)
{
  const char		*tmp;

  settings->pos = efget_pos_cnf(cnf);
  settings->size = efget_size_cnf(cnf, "components.size");
  bunny_configuration_getf(cnf, &tmp, "components.name");
  if ((settings->name = efstrdup(tmp)) == NULL)
    return(-1);
  bunny_configuration_getf(cnf, &tmp, "components.filename");
  if ((settings->filename = efstrdup(tmp)) == NULL)
    {
      bunny_free((char *)settings->name);
      return(-1);
    }
  return(0);
}

int			efadd_picture_cnf(t_bunny_configuration		*cnf,
					  t_gui				*gui)
{
  t_picture_settings	settings;

  if (init_picture_settings(cnf, &settings) == -1)
      return(-1);
  efadd_picture_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  return(0);
}
