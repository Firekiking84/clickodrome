#include "gui.h"

void efadd_label_cnf(t_bunny_configuration *cnf,t_gui *gui)
{
  t_label *label;
  t_zposition pos;
  t_bunny_size size;
  const char *name;
  const char *text;
  t_bunny_color color;
  t_bunny_color bg;
  t_component *comp;

  comp = bunny_malloc(sizeof(t_component));
  pos = efget_posz_cnf(cnf);
  size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf,&name,"components.name");
  bunny_configuration_getf(cnf,&text,"components.text");
  bg = efget_color_cnf(cnf,"bg");
  color = efget_color_cnf(cnf,"font_color");
  label = efnew_label(&pos,size,name,text,&color,&bg);

  //efadd_label_gui(gui,name,pos,size,text,&color,&hover_color,&bg);
  efvector_push(efvector_at(gui->divs,gui->divs->data_count,t_div).labels,label);
  comp->component = efvector_at(gui->divs,gui->divs->data_count,t_div).labels;
  comp->type = 2;
  efvector_push(gui->components,comp);
}
