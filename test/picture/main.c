#include		"picture.h"

int			main()
{
  t_bunny_zpixelarray	*zpx;
  t_bunny_pixelarray	*font;
  t_bunny_window	*window;
  t_picture_settings	set;
  t_picture		*picture;

  /*
  ** if (argc != 2)
  **   {
  **     perror("argument invalide");
  **     return (-1);
  **   }
   */

  set.pos.x = 0;
  set.pos.y = 0;
  set.pos.z = 500;
  set.size.x = 1920;
  set.size.y = 1080;
  set.name = malloc(strlen("image1"));
  strcpy(set.name, "image1");
  set.filename = malloc(strlen("satoru.jpg"));
  strcpy(set.filename, "satoru.jpg");
  picture = efnew_picture(&set);
  zpx = malloc(sizeof(t_bunny_zpixelarray));
  zpx->z = malloc(sizeof(double) * 1920 * 1080);
  window = bunny_start(1920, 1080, false, "clickodrome");
  zpx->px = bunny_new_pixelarray(1920, 1080);
  efclear_zbuffer(zpx);
  efdisplay_picture(picture, zpx);
  bunny_blit(&window->buffer, &zpx->px->clipable, NULL);
  bunny_display(window);
  bunny_usleep(10000000);
  /*
  bunny_set_event_response(efevent_gui);
  bunny_set_loop_main_function(loop_function);
  bunny_set_display_function(display_function);
  bunny_loop(prog->window, 60, prog);
  */
}