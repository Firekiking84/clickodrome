#include		"timer.h"
#include		"string.h"
#include		"unistd.h"

void			ecrit(void)
{
  write(1, "salamaleykoum\n", 14);
}

int			main()
{
  t_timer_settings	set;
  t_timer		*time;
  t_vector_ptr		*func;

  func = efvector_ptr_new(64);
  efvector_ptr_push(func, ecrit);
  set.functions = func;
  set.delay = 5000;
  set.name = bunny_malloc(strlen("image1") + 1);
  strcpy(set.name, "image1");
  time = efnew_timer(&set);
  while (1)
    {
      efrefresh_timer(time);
    }
  /*
  bunny_set_event_response(efevent_gui);
  bunny_set_loop_main_function(loop_function);
  bunny_set_display_function(display_function);
  bunny_loop(prog->window, 60, prog);
  */
}
