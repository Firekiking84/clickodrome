#include		"text_box.h"
#include		"vector.h"

#include		<stdlib.h>
#include		<stdio.h>

typedef struct		s_data
{
  t_bunny_zpixelarray	px;
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
  i = 0;
  while (i < (500 * 500))
    {
      data->px.z[i] = 10000000;
      i += 1;
    }
  efdisplay_text_box(data->box, &data->px);
  bunny_blit(&data->win->buffer, &data->px.px->clipable, &data->origin);
  bunny_display(data->win);
  /*
  ** printf("Len str : %d ; cursor_pos : %d ; str : %s \r",
  ** 	 data->box->text->str_len, data->box->cursor_pos, data->box->text->str);
   */
  return(GO_ON);
}

int			main(void)
{
  t_data		data;
  t_vector		*functions;
  t_bunny_size		size;
  t_bunny_color		col;
  t_bunny_color		bg;
  t_zposition		pos;

  pos.z = 1;
  pos.x = 0;
  pos.y = 0;
  data.origin.x = 0;
  data.origin.y = 0;
  size.x = 100;
  size.y = 100;
  data.win = bunny_start(500, 500, false, "Test texbox");
  data.px.px = bunny_new_pixelarray(500, 500);
  data.px.z = malloc(sizeof(double) * (500 * 500));
  functions = efvector_new(size_t, 1);
  size_t tmp = (size_t)(void*)print_result;

  efvector_push(functions, &tmp);
  col.full = WHITE;
  bg.full = BLACK;
  data.box = efnew_text_box(pos, size, "test", col, &bg, functions);
  bunny_set_event_response(eventResponse);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, 60, &data);
}
