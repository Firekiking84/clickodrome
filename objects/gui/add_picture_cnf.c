#include		"gui.h"

static int		init_picture_settings(t_bunny_configuration	*cnf,
					      t_picture_settings	*settings)
{
  const char		*tmp;

  settings->pos = efget_posz_cnf(cnf);
  settings->size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf, &tmp, "components.name");
  if ((settings->name = strdup(tmp)) == NULL)
    return(-1);
  bunny_configuration_getf(cnf, &settings->filename, "components.filename");
  if ((settings->filename = strdup(tmp)) == NULL)
    {
      free(settings->name);
      return(-1);
    }
  return(0);
}

int			efadd_picture_cnf(t_bunny_configuration		*cnf,
					  t_gui				*gui)
{
  t_picture		*picture;
  t_component		*comp;
  t_picture_settings	settings;


  comp = bunny_malloc(sizeof(t_component));
  if (!comp)
    return(-1);
  if (init_picture_settings(cnf, &settings) == -1)
    {
      free(comp);
      return(-1);
    }
  comp->component = efadd_picture_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  if (!comp->component)
    {
      free(comp);
      free(settings.name);
      free(settings.filename);
      return(-1);
    }
  comp->type = PICTURE;
  efvector_ptr_push(gui->components, comp);
}