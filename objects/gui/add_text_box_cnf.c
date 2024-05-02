#include		"gui.h"

static int		init_textbox_settings(t_bunny_configuration	*cnf,
					      t_gui			*gui,
					      t_textbox_settings	*settings)
{
  const char		*tmp;

  settings->pos = efget_posz_cnf(cnf);
  settings->size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf, tmp, "components.name");
  settings->name = strdup(tmp);
  if (!settings->name)
    return(-1);
  settings->color = efget_color_cnf(cnf, "font_color");
  settings->bg = efget_color_cnf(cnf, "bg");
  settings->functions = get_functions(cnf, gui);
  if (!settings->functions)
    {
      free(settings->name);
      return(-1);
    }
  return(0);
}

int 			efadd_text_box_cnf(t_bunny_configuration	*cnf,
					   t_gui			*gui)
{
  t_textbox_settings	settings;
  t_component		*comp;

  init_textbox_settings(cnf, gui, &settings);
  comp = bunny_malloc(sizeof(t_component));
  if (!comp)
    return(-1);
  comp->component = efadd_text_box_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  comp->type = TEXTBOX;
  efvector_ptr_push(gui->components, comp);
  return(0);
}
