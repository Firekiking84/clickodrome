#include		"picture.h"
#include		"lapin.h"
#include		"draw.h"
#include		"div.h"
#include		"gui.h"
#include		"vector_ptr.h"
#include		<stddef.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<lapin.h>
#include		<stdio.h>

typedef struct s_data
{
  t_picture_settings		edit;
  t_bunny_window		*win;
  t_picture			*picture;
  t_gui				*gui;
}t_data;

t_bunny_response           display(void                    *_data)
{
  t_data		   *data;

  data = (t_data *)_data;
  efdisplay_gui(data->gui, data->picture->img);
  bunny_blit(&data->win->buffer,&data->picture->img->clipable, NULL);
  bunny_display(data->win );
  return(GO_ON);
}
int			main()

{
  t_data		data;

  data.picture = efnew_picture(&data.edit);
  if (data.picture == NULL)
    return(1);
  data.gui = efnew_gui(data.edit.filename);
  data.win = bunny_start(1920, 1080, false, "clickodrome");
  data.picture->img = bunny_new_pixelarray(data.edit.size.x, data.edit.size.y);
  bunny_set_loop_main_function(display);
  bunny_loop(data.win, 40, &data.picture);
  bunny_stop(data.win);
  return(0);
}
