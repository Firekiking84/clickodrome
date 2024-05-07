#include "button.h"
#include "vector.h"
#include "lapin.h"
#include "draw.h"
#include "vector_ptr.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct			 s_data
{
  t_bunny_pixelarray		px;
  t_bunny_position		origin;
  t_bunny_window		*win;
  t_button			*button;
}				t_data;

void				 print_pressed()
{
  printf("Je suis pressé !");
}
t_bunny_response		 eventResponse (t_bunny_event const  *event,
						void *_data)
{
  t_data			*data;

  data = (t_data *)_data;
  efevents_button(data->button, event);
  return(GO_ON);
}
t_bunny_response		loop(void	*data2)
{
  t_data			*data;
  int				i;

  data = (t_data *)data2;
  efdisplay_button(data->button, &data->px);
  bunny_blit(&data->win->buffer, &data->px->clipable, &data->origin);
  bunny_display(data->win);
  return(GO_ON);
}

int				 main(void)
{
  t_data			 data;
  t_button_settings		 set;

  set.pos.x = 0;
  set.pos.y = 0;
  data.origin.x = 0;
  data.origin.y = 0;
  set.size.x = 100;
  set.size.y = 100;
  set.text = "BUTTON";
  set.name = " 123";
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
  set.hover_color = bunny_malloc(sizeof(t_bunny_color));
  set.hover_color->full = RED;
  data.win = bunny_start(500, 500, false, "Test button");
  data.px = bunny_new_pixelarray(500, 500);
  data.button = efnew_button(&set);
  efclear_zbuffer(&data.px);
  bunny_set_event_response(eventResponse);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, 60, &data);
}
