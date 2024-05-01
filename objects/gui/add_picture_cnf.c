#include "gui.h"

void efadd_picture_cnf(t_bunny_configuration *cnf,t_gui *gui)
{
  t_picture *picture;
  t_zposition pos;
  t_bunny_size size;
  const char *name;
  const char *filename;
  t_component *comp;

  comp = bunny_malloc(sizeof(t_component));
  pos = efget_posz_cnf(cnf);
  size = efget_size_cnf(cnf);
  bunny_configuration_getf(cnf,&name,"components.name");
  bunny_configuration_getf(cnf,&filename,"components.filename");
  picture = efnew_picture(&pos,size,name,filename);
  efadd_picture_gui(gui,pos,size,name,filename);


  //efadd_picture_gui(gui,name,pos,size,filename);

  efvector_push(efvector_at(gui->divs,gui->divs->data_count,t_div).pictures,picture);
  comp->component = efvector_at(gui->divs,gui->divs->data_count,t_div).pictures;
  comp->type = 3;
  efvector_push(gui->components,comp);
}
