#include		"clickodrome.h"

#include		<stddef.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
typedef struct s_data
{
  t_bunny_window		*win;
  t_bunny_pixelarray		*px;
  t_gui				*gui;
}t_data;

t_bunny_response           display(void                    *_data)
{
  t_data		   *data;

  data = (t_data *)_data;
  efdisplay_gui(data->gui, data->px);
  bunny_blit(&data->win->buffer, &data->px->clipable, NULL);
  bunny_display(data->win);
  return(GO_ON);
}

int			main()

{
  t_data		data;

  bunny_set_error_descriptor(2);
  data.gui = efnew_gui("./portrait.dab");
  data.win = bunny_start(data.gui->screen_size.x, data.gui->screen_size.y, false, "Démo Portrait");
  data.px = bunny_new_pixelarray(data.gui->screen_size.x, data.gui->screen_size.y);
  bunny_set_display_function(display);
  bunny_loop(data.win, 30, &data);
  bunny_stop(data.win);
  return(0);
}
