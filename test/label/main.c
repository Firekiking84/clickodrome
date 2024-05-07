#include		"label.h"

#include		<stdio.h>

int			main()
{
  t_bunny_pixelarray	*px;
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
  bunny_set_memory_check(true);
  bunny_set_maximum_ram(20 * 1024 * 1024);
  set.pos.x = 900;
  set.pos.y = 500;
  set.pos.z = 0;
  set.size.x = 240;
  set.size.y = 80;
  set.name = bunny_malloc(strlen("UTILITE DE KERYAN") + 1);
  if (!set.name)
    {
      perror("Malloc error set.name");
      return(1);
    }
  strcpy(set.name, "UTILITE DE KERYAN");
  set.text = bunny_malloc(strlen("sert a rien\nsert a rien\nnul a overwatch") + 1);
  if (!set.text)
    {
      perror("Malloc error set.text");
      return(1);
    }
  strcpy(set.text, "sert a rien\nsert a rien\nnul a overwatch");
  set.font_color = bunny_malloc(sizeof(t_bunny_color));
  if (!set.font_color)
    {
      perror("Malloc error set.font_color");
      return(1);
    }
  set.font_color->full = BLACK;
  set.bg = bunny_malloc(sizeof(t_bunny_color));
  if (!set.bg)
    {
      perror("Malloc error set.bg");
      return(1);
    }
  set.bg->full = GREEN;
  set.font = bunny_malloc(sizeof(char) * (strlen("../../res/font.png") + 1));
  if (!set.font)
    {
      perror("Malloc error set.font");
      return(1);
    }
  strcpy(set.font, "../../res/font.png");
  la = efnew_label(&set);
  window = bunny_start(1920, 1080, false, "clickodrome");
  px = bunny_new_pixelarray(1920, 1080);
  if (!px)
    {
      bunny_perror("Bunny_new_pixelarray error");
      return(1);
    }
  efclear_zbuffer(px);
  efdisplay_label(la, px);
  bunny_blit(&window->buffer, &px->clipable, NULL);
  bunny_display(window);
  bunny_usleep(10000000);
  /*
  bunny_set_event_response(efevent_gui);
  bunny_set_loop_main_function(loop_function);
  bunny_set_display_function(display_function);
  bunny_loop(prog->window, 60, prog);
  */
}
