#include "gui.h"

void efadd_button_cnf(t_bunny_configuration *cnf,t_gui *gui)
{
  int i;
  int j;
  i = 1;
  void *link;
  t_button *button;
  t_zposition pos;
  t_bunny_size size;
  const char *name;
  const char *text;
  const char *lib;
  t_bunny_color color;
  t_bunny_color bg;
  t_bunny_color hover_color;
  t_component *comp;
  t_vector *function;
  void *func_ptr;
  size_t tptr;
  const char *func;

  comp = bunny_malloc(sizeof(t_component));
  pos = efget_posz_cnf(cnf);
  size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf,&name,"components.name");
  bunny_configuration_getf(cnf,&text,"components.text");
  color = efget_color_cnf(cnf,"font_color");
  bg = efget_color_cnf(cnf,"bg");
  hover_color = efget_color_cnf(cnf,"hover_color");
  j = bunny_configuration_casesf(cnf,"components.functions");

  if (j > 0)
    {
      bunny_configuration_getf(cnf,&lib,"components.functions[0]");
      link = dlopen(lib, RTLD_NOW); // lib needs to contain path to the library
    }
  function = efvector_new(size_t,j);
  while (i <  j)
    {
      bunny_configuration_getf(cnf,&func,"components.functions[%d]",i);
      func_ptr = dlsym(link,func);
      efvector_push(function,(size_t)(&func_ptr));
      i++;
    }

  button = efnew_button(&pos,size,name,text,&hover_color,&color,&bg,function);

  //efadd_button_gui(gui,name,pos,size,text,&color,&hover_color,&bg,function);
  efvector_push(efvector_at(gui->divs,gui->divs->data_count,t_div).buttons,button);
  comp->component = efvector_at(gui->divs,gui->divs->data_count,t_div).buttons;
  comp->type = 0;
  efvector_push(gui->components,comp);
  efvector_push(gui->libs,link);
}

