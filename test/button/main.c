#include			"gui.h"

#include			<stddef.h>
#include			<string.h>
#include			<stdio.h>

typedef struct			 s_data
{
  t_bunny_pixelarray		*px;
  t_bunny_position		origin;
  t_bunny_window		*win;
  t_button			*button;
}				t_data;

void				 print_pressed(t_gui		*gui,
					       void		*data)
{
  printf("Je suis pressé !\n");
}

t_bunny_response		 eventResponse (t_bunny_event const  *event,
						void *_data)
{
  t_data			*data;

  data = (t_data *)_data;
  efevent_button(data->button, event);
  return(GO_ON);
}

t_bunny_response		loop(void	*data2)
{
  t_data			*data;

  data = (t_data *)data2;
  efdisplay_button(data->button, data->px);
  bunny_blit(&data->win->buffer, &data->px->clipable, &data->origin);
  bunny_display(data->win);
  return(GO_ON);
}

int				main(void)
{
  t_data			data;
  t_button_settings		set;
  t_lib				lib;

  set.pos.x = 0;
  set.pos.y = 0;
  data.origin.x = 0;
  data.origin.y = 0;
  set.size.x = 100;
  set.size.y = 100;
  set.text = "BUTTON";
  set.name = "123";
  lib.name = NULL;
  lib.div_name = NULL;
  lib.link = NULL;
  lib.data = NULL;
  set.lib = &lib;
  set.functions = efvector_ptr_new(1);
  efvector_ptr_push(set.functions, print_pressed);
  set.font_size.x = 10;
  set.font_size.y = 14;
  set.font = bunny_malloc(sizeof(char) * strlen("font.png") +1);
  strcpy(set.font, "font.png");
  set.font_color = bunny_malloc(sizeof(t_bunny_color));
  set.font_color->full = WHITE;
  set.bg = bunny_malloc(sizeof(t_bunny_color));
  set.bg->full = BLACK;
  set.click_color = bunny_malloc(sizeof(t_bunny_color));
  set.click_color->full = BLUE;
  set.hover_color = bunny_malloc(sizeof(t_bunny_color));
  set.hover_color->full = RED;
  data.win = bunny_start(500, 500, false, "Test button");
  data.px = bunny_new_pixelarray(500, 500);
  data.button = efnew_button(&set);
  bunny_set_event_response(eventResponse);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, 60, &data);
}
