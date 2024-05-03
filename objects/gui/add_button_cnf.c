#include		"gui.h"

#include		<string.h>

static int		init_button_settings(t_bunny_configuration	*cnf,
					     t_button_settings		*settings,
					     t_gui *gui)
{
  const char		*tmp;

  settings->pos = efget_posz_cnf(cnf);
  settings->size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf, &tmp, "components.name");
  if ((settings->name = strdup(tmp)) == NULL)
    return(-1);
  bunny_configuration_getf(cnf, &tmp, "components.text");
  if ((settings->text = strdup(tmp)) == NULL)
    {
      bunny_free(settings->name);
      return(-1);
    }
  bunny_configuration_getf(cnf, &tmp, "components.font");
  settings->font = strdup(tmp);
  if (!settings->font)
    {
      bunny_free(settings->name);
      bunny_free(settings->text);
      return(-1);
    }
  settings->font_size = efget_font_size_cnf(cnf);
  settings->font_color = efget_color_cnf(cnf, "font_color");
  settings->bg = efget_color_cnf(cnf, "bg");
  settings->hover_color = efget_color_cnf(cnf, "hover_color");
  if ((settings->function = efget_functions(cnf, gui)) == NULL)
    {
      bunny_free(settings->font);
      bunny_free(settings->name);
      bunny_free(settings->text);
      return(-1);
    }
  return(0);
}

int			efadd_button_cnf(t_bunny_configuration		*cnf,
					 t_gui				*gui)
{
  t_component		*comp;
  t_button_settings	settings;

  comp = bunny_malloc(sizeof(t_component));
  if (!comp)
    return(-1);
  if (init_button_settings(cnf, &settings,gui) == -1)
    {
      bunny_free(comp);
      return(-1);
    }
  comp->component = efadd_button_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  if (!comp->component)
    {
      bunny_free(comp);
      bunny_free(settings.name);
      bunny_free(settings.text);
      return(-1);
    }
  comp->type = BUTTON;
  efvector_ptr_push(gui->components, comp);
  return(1);
}

