#include "gui.h"

void efadd_text_box_cnf(t_bunny_configuration *cnf,t_gui *gui)
{
  int i;
  int j;
  i = 1;
  void *link;
  t_text_box *text_box;
  t_bunny_position pos;
  t_bunny_size size;
  const char *name;
  const char *text;
  const char *lib;
  t_bunny_color color;
  t_bunny_color bg;
  t_component *comp;
  t_vector *function;
  void *func_ptr;
  const char *func;

  comp = bunny_malloc(sizeof(t_component));
  pos = efget_pos_cnf(cnf);
  size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf,&name,"components.name");
  bunny_configuration_getf(cnf,&text,"components.text");
  color = efget_color_cnf(cnf,"font_color");
  bg = efget_color_cnf(cnf,"bg");

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
      efvector_push(function,func_ptr);
      i++;
    }

  text_box = efnew_text_box(&pos,size,name,text,&color,&bg,function);

  //efadd_button_gui(gui,name,pos,size,text,&color,&hover_color,&bg,function);
  efvector_push(efvector_at(gui->divs,gui->divs->data_count,t_div).text_boxes,text_box);
  comp->component = efvector_at(gui->divs,gui->divs->data_count,t_div).text_boxes;
  comp->type = 1;
  efvector_push(gui->components,comp);
  efvector_push(gui->libs,link);
}
