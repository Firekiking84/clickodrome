#include		"gui.h"

static int		init_textbox_settings(t_bunny_configuration	*cnf,
					      t_gui			*gui,
					      t_textbox_settings	*settings)
{
  const char		*tmp;

  settings->pos = efget_posz_cnf(cnf);
  settings->size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf, &tmp, "components.name");
  settings->name = strdup(tmp);
  if (!settings->name)
    return(-1);
  bunny_configuration_getf(cnf, &tmp, "components.font");
  settings->font = strdup(tmp);
  if (!settings->font)
    {
      free(settings->name);
      free(settings->text);
      return(-1);
    }
  settings->font_size = efget_font_size_cnf(cnf);
  settings->font_color = efget_color_cnf(cnf, "font_color");
  settings->bg = efget_color_cnf(cnf, "bg");
  settings->functions = efget_functions(cnf, gui);
  if (!settings->functions)
    {
      free(settings->font);
      free(settings->name);
      free(settings->font);
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
