#include		"label.h"

int			main()
{
  t_bunny_zpixelarray	*zpx;
  t_bunny_pixelarray	*font;
  t_bunny_window	*window;
  t_label_settings	set;
  t_label		*la;

  /*
  ** if (argc != 2)
  **   {
  **     perror("argument invalide");
  **     return (-1);
  **   }
   */
  set.pos.x = 900;
  set.pos.y = 500;
  set.pos.z = 0;
  set.size.x = 240;
  set.size.y = 80;
  set.name = malloc(strlen("UTILITE DE KERYAN"));
  strcpy(set.name, "UTILITE DE KERYAN");
  set.text = malloc(strlen("sert a rien\nsert a rien\nnul a overwatch"));
  strcpy(set.text, "sert a rien\nsert a rien\nnul a overwatch");
  set.font_color.full = BLACK;
  set.bg.full = GREEN;
  la = efnew_label(&set);
  zpx = malloc(sizeof(t_bunny_zpixelarray));
  zpx->z = malloc(sizeof(double) * 1920 * 1080);
  window = bunny_start(1920, 1080, false, "clickodrome");
  font = bunny_load_pixelarray("../../res/font.png");
  zpx->px = bunny_new_pixelarray(1920, 1080);
  efclear_zbuffer(zpx);
  efdisplay_label(la, zpx, font);
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
