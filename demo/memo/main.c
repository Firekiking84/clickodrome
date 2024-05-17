#include		"clickodrome.h"

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*px;
  t_gui			*gui;
}			t_data;

t_bunny_response	event_response(t_bunny_event const	*event,
				       void			*data2)
{
  t_data		*data;

  data = (t_data *)data2;
  efevent_gui(event, data->gui);
  return(GO_ON);
}

t_bunny_response	loop(void				*data2)
{
  t_data		*data;

  data = (t_data *)data2;
  efrefresh_gui(data->gui);
  return(manage_continue(data->gui));
}

t_bunny_response	display(void				*data2)
{
  t_data		*data;

  data = (t_data *)data2;
  efdisplay_gui(data->gui, data->px);
  bunny_blit(&data->win->buffer, &data->px->clipable, NULL);
  bunny_display(data->win);
  return(GO_ON);
}

int			main(void)
{
  t_data		data;

  bunny_set_error_descriptor(2);
  data.gui = efnew_gui("./memo.dab");
  data.win = bunny_start(data.gui->screen_size.x, data.gui->screen_size.y, false, "Demo Exit ME");
  data.px = bunny_new_pixelarray(data.gui->screen_size.x, data.gui->screen_size.y);
  bunny_set_loop_main_function(loop);
  bunny_set_display_function(display);
  bunny_set_event_response(event_response);
  bunny_loop(data.win, 30, &data);
  bunny_stop(data.win);
  return(0);
}
