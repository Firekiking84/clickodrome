/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:42:14 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

#include		<string.h>

static int		init_label_settings(t_bunny_configuration	*cnf,
					    t_label_settings		*settings)
{
  const char		*tmp;

  settings->pos = efget_pos_cnf(cnf);
  settings->size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf, &tmp, "components.name");
  settings->name = strdup(tmp);
  if (!settings->name)
    return(-1);
  bunny_configuration_getf(cnf, &tmp, "components.text");
  settings->text = strdup(tmp);
  if (!settings->text)
    {
      bunny_free(settings->name);
      return(-1);
    }
  settings->bg = efget_color_cnf(cnf, "bg");
  bunny_configuration_getf(cnf, &tmp, "components.font");
  settings->font = strdup(tmp);
  if (!settings->font)
    {
      bunny_free(settings->text);
      bunny_free(settings->name);
      return(-1);
    }
  settings->font_size = efget_font_size_cnf(cnf);
  settings->font_color = efget_color_cnf(cnf, "font_color");
  return(0);
}

int			efadd_label_cnf(t_bunny_configuration		*cnf,
					t_gui				*gui)
{
  t_label_settings	settings;
  t_component		*comp;

  comp = bunny_malloc(sizeof(t_component));
  if (!comp)
    return(-1);
  if (init_label_settings(cnf, &settings) == -1)
    {
      bunny_free(comp);
      return(-1);
    }
  comp->component = efadd_label_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  comp->type = LABEL;
  efvector_ptr_push(gui->components, comp);
  return(0);
}
