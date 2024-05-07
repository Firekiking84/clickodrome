/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:42:28 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

static int		init_textbox_settings(t_bunny_configuration	*cnf,
					      t_gui			*gui,
					      t_textbox_settings	*settings)
{
  const char		*tmp;

  settings->pos = efget_pos_cnf(cnf);
  settings->size = efget_size_cnf(cnf, "components.size");
  bunny_configuration_getf(cnf, &tmp, "components.name");
  settings->name = strdup(tmp);
  if (!settings->name)
    return(-1);
  bunny_configuration_getf(cnf, &tmp, "components.font");
  settings->font = strdup(tmp);
  if (!settings->font)
    {
      bunny_free(settings->name);
      return(-1);
    }
  settings->font_size = efget_size_cnf(cnf, "components.font_size");
  settings->font_color = efget_color_cnf(cnf, "font_color");
  settings->bg = efget_color_cnf(cnf, "bg");
  settings->functions = efget_functions(cnf, gui);
  if (!settings->functions)
    {
      bunny_free(settings->font);
      bunny_free(settings->name);
      return(-1);
    }
  return(0);
}

int 			efadd_text_box_cnf(t_bunny_configuration	*cnf,
					   t_gui			*gui)
{
  t_textbox_settings	settings;
  t_component		*comp;

  if (init_textbox_settings(cnf, gui, &settings) == -1)
    return(-1);
  comp = bunny_malloc(sizeof(t_component));
  if (!comp)
    return(-1);
  comp->component = efadd_text_box_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  comp->type = TEXTBOX;
  efvector_ptr_push(gui->components, comp);
  return(0);
}
