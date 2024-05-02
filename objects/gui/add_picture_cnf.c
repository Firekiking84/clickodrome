#include		"gui.h"

static void		init_picture_settings(t_bunny_configuration	*cnf,
					      t_textbox_settings	*settings)
{
  settings->pos = efget_posz_cnf(cnf);
  settings->size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf, &settings->name, "components.name");
  bunny_configuration_getf(cnf, &settings->filename, "components.filename");
}

int			efadd_picture_cnf(t_bunny_configuration		*cnf,
					  t_gui				*gui)
{
  t_component		*comp;

  init_picture_settings(cnf, &settings);
  comp = bunny_malloc(sizeof(t_component));
  if (!comp)
    return(-1);
  comp->component = efadd_picture_div(efvector_at(gui->divs, gui->divs->data_count - 1, t_div), &settings);
  comp->type = PICTURE;
  efvector_push(gui->components, comp);
}
