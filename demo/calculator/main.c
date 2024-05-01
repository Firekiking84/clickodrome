#include		"clickodrome.h"

int			main(int		argc,
			     char		**argv)
{
  t_program		*prog;

  if (argc != 2)
    {
      perror("argument invalide");
      return (-1);
    }
  prog = malloc(sizeof(prog));
  prog->window = bunny_start(1920, 1080, false, "clickodrome");
  prog->font = bunny_load_pixelarray("../res/font.png");
  prog->zpx->px = bunny_new_pixelarray(1920, 1080);
  prog->gui = efnew_gui(argv[1]);
  bunny_set_event_response(efevent_gui);
  bunny_set_loop_main_function(loop_function);
  bunny_set_display_function(display_function);
  bunny_loop(prog->window, 60, prog);
}
