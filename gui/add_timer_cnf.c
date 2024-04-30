#include "gui.h"

void efadd_timer_cnf(t_bunny_configuration *cnf,t_gui *gui)
{
  int i;
  int j;
  i = 1;
  void *link;
  t_timer *timer;
  const char* name;
  const char *lib;
  int delay;
  t_component *comp;
  t_vector *function;
  void *func_ptr;
  size_t tptr;
  const char *func;

  comp = bunny_malloc(sizeof(t_component));

  bunny_configuration_getf(cnf,&name,"components.name");
  bunny_configuration_getf(cnf,&delay,"components.delay");

  j = bunny_configuration_casesf(cnf,"components.functions");

  if (j > 0)
    {
      bunny_configuration_getf(cnf,&lib,"components.functions[0]");
      link = dlopen(lib, RTLD_NOW); // lib needs to contain path to the library
    }
  function = efvector_new(func_ptr,j);
  while (i <  j)
    {
      bunny_configuration_getf(cnf,&func,"components.functions[%d]",i);
      func_ptr = dlsym(link,func);
      tptr = (size_t)func_ptr;
      efvector_push(function,&tptr);
      i++;
    }

  timer = efnew_timer(name,delay,function);

  //efadd_button_gui(gui,name,pos,size,text,&color,&hover_color,&bg,function);
  efvector_push(efvector_at(gui->divs,gui->divs->data_count,t_div).timer,timer);
  comp->component = efvector_at(gui->divs,gui->divs->data_count,t_div).timer;
  comp->type = 1;
  efvector_push(gui->components,comp);
  efvector_push(gui->libs,link);
}
