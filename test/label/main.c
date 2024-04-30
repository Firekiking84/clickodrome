#include		"lab.h"

int			main()
{
  t_program		*prog;
  t_label		*la;
  t_zposition		zp;
  t_bunny_size		size;
  t_bunny_color		fc;
  t_bunny_color		bg;

  /*
  ** if (argc != 2)
  **   {
  **     perror("argument invalide");
  **     return (-1);
  **   }
   */
  zp.x = 900;
  zp.y = 500;
  zp.z = 0;
  size.x = 240;
  size.y = 80;
  fc.full = BLACK;
  bg.full = GREEN;
  la = efnew_label(&zp, size, "UTILITE DE KERYAN", "sert a rien\nsert a rien\nnul a overwatch", &fc, NULL);
  prog = malloc(sizeof(prog));
  prog->zpx = malloc(sizeof(t_bunny_zpixelarray*));
  prog->zpx->z = malloc(sizeof(double) * 1920 * 1080);
  prog->window = bunny_start(1920, 1080, false, "clickodrome");
  prog->font = bunny_load_pixelarray("../../res/font.png");
  prog->zpx->px = bunny_new_pixelarray(1920, 1080);
  efclear_zbuffer(prog->zpx);
  efdisplay_label(la, prog->zpx, prog->font);
  bunny_blit(&prog->window->buffer, &prog->zpx->px->clipable, NULL);
  bunny_display(prog->window);
  bunny_usleep(10000000);
  /*
  bunny_set_event_response(efevent_gui);
  bunny_set_loop_main_function(loop_function);
  bunny_set_display_function(display_function);
  bunny_loop(prog->window, 60, prog);
  */
}
