#include "button.h"
#include "vector.h"
#include "lapin.h"

#include <stdio.h>
#include <stdlib.h>
typedef struct			 s_data
{
  t_bunny_zpixelarray		px;
  t_bunny_position		origin;
  t_bunny_window		*win;
  t_button			*button;
}t_data;
void				 print_resutl(const char *str)
{
  printf("j'ai reçu :%s\n", str);
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
  i = 0;
  while (i<(500 *500))
    {
      data->px.z[i] = 10000000;
      i ++;
    }
  efdisplay_button(data->button, &data->px);
  bunny_blit(&data->win->buffer, &data->px.px->clipable, &data->origin);
  bunny_display(data->win);
  return(GO_ON);
}
int				 main(void)
{
  t_data			 data;
  t_zposition			 pos;
  t_bunny_size			 size;
  const char			 *name;
  const char			 *text;
  t_bunny_color			 font_color;
  t_bunny_color			 hover_color;
  t_bunny_color			 bg;
  t_vector			 *functions;

  pos.z = 1;
  pos.x = 0;
  pos.y = 0;
  data.origin.x = 0;
  data.origin.y = 0;
  size.x = 100;
  size.y = 100;
  text = "BUTTON";
  name = " 123";
  data.win = bunny_start(500, 500, false, "Test button");
  data.px.px = bunny_new_pixelarray(500, 500);
  data.px.z = malloc(sizeof(double) * (500 * 500));
  functions = efvector_new(size_t, 1);
  size_t tmp = (size_t)(void*)print_resutl;
  efvector_push(functions, &tmp);
  font_color.full = WHITE;
  bg.full = BLACK;
  hover_color.full = RED;
  data.button = efnew_button(&pos , size,name ,text ,&font_color ,&hover_color ,&bg ,functions);
  bunny_set_event_response(eventResponse);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, 60, &data);
}
