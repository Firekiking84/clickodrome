#include	"gui.h"

#include	<string.h>

static int		init_timer_settings(t_bunny_configuration	*cnf,
					    t_gui			*gui,
					    t_timer_settings		*settings)
{
  const char		*tmp;
  int			delay;

  bunny_configuration_getf(cnf, &tmp, "components.name");
  settings->name = strdup(tmp);
  if (!settings->name)
    return(-1);
  bunny_configuration_getf_int(cnf, &delay, "components.delay");
  settings->delay = (size_t)delay;
  if (!settings->delay)
    {
      free(settings->delay);
      return(-1);
    }
  settings->functions = efget_functions(cnf, gui);
  if (!settings->functions)
    {
      free(settings->name);
      free(settings->delay);
      return(-1);
    }
  return(0);
}

int			efadd_timer_cnf(t_bunny_configuration		*cnf,
					t_gui				*gui)
{
  t_timer_settings	*settings;
  t_component		*comp;

  comp = bunny_malloc(sizeof(t_component));
  if (!comp)
    return(-1);
  if (init_timer_settings(cnf, gui, &settings) == -1)
    {
      free(comp);
      return(-1);
    }
  comp->component = efadd_timer_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  comp->type = TIMER;
  efvector_ptr_push(gui->components, comp);
  return(0);
}
