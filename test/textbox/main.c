#include		"text_box.h"
#include		"vector.h"

#include		<stdlib.h>
#include		<stdio.h>

typedef struct		s_data
{
  t_bunny_pixelarray	*px;
  t_bunny_position	origin;
  t_bunny_window	*win;
  t_text_box		*box;
}			t_data;

void			print_result(const char	*	str)
{
  printf("J'ai reçu : %s\n", str);
}

t_bunny_response	eventResponse(t_bunny_event const	*event,
				      void			*_data)
{
  t_data		*data;

  data = (t_data *)_data;
  efevent_text_box(data->box, event);
  return(GO_ON);
}

t_bunny_response	loop(void			*data2)
{
  t_data		*data;
  int			i;

  data = (t_data *)data2;
  efdisplay_text_box(data->box, &data->px);
  bunny_blit(&data->win->buffer, &data->px->clipable, &data->origin);
  bunny_display(data->win);
  return(GO_ON);
}

int			main(void)
{
  t_data		data;
  t_textbox_settings	settings;

  settings.pos.x = 0;
  settings.pos.y = 0;
  data.origin.x = 0;
  data.origin.y = 0;
  settings.size.x = 100;
  settings.size.y = 100;
  data.win = bunny_start(500, 500, false, "Test texbox");
  data.px = bunny_new_pixelarray(500, 500);
  settings.functions = efvector_ptr_new(1);
  efvector_ptr_push(settings.functions, print_result);
  settings.font_color = bunny_malloc(sizeof(t_bunny_color));
  settings.font_color->full = WHITE;
  settings.bg = bunny_malloc(sizeof(t_bunny_color));
  if (!settings.bg)
    return(1);
  settings.bg->full = BLACK;
  settings.name = strdup("test");
  data.box = efnew_text_box(&settings);
  if (!data.box)
    return(1);
  bunny_set_event_response(eventResponse);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, 60, &data);
  return(0);
}
