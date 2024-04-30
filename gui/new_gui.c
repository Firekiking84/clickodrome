#include "gui.h"

t_gui *efnew_gui(const char *file)
{
  t_bunny_configuration *cnf;
  t_bunny_configuration *div;
  t_bunny_configuration *components;
  t_gui *gui;
  t_div *tdiv;
  const char *divname;
  const char *type;
  t_zposition pos;
  t_bunny_size size;
  int tenum;
  int i;
  int j;
  int nbr_divs;
  int nbr_components;
  cnf = bunny_open_configuration(file,NULL);
  if (cnf == NULL)
    {
      puts("Failed to open file");
      return(NULL);
    }
  nbr_components = bunny_configuration_casesf(cnf,"components");
  nbr_divs = bunny_configuration_childrenf(cnf,"[]");
  gui = bunny_malloc(sizeof(t_gui));
  gui->components = _efvector_new(sizeof(t_vector),nbr_components);
  gui->components = efvector_new(div,nbr_divs);
  div = bunny_configuration_first(cnf);
  while (div != bunny_configuration_end(cnf))
    {
      bunny_configuration_getf(div,&divname,"[]");
      pos = efget_posz_cnf(div);
      size = efget_size_cnf(div);
      tdiv = efnew_div(divname,pos,size);
      efvector_push(gui->divs,tdiv);
      j++;
      i = 0;
      while (bunny_configuration_getf(div, &components, "components[%d]", i))
	{
	  bunny_configuration_getf(cnf,&type,"components[%d].type",i);
	  tenum = efcomp_type(type);
	  if(tenum == 0)
	    {
	      efadd_button_cnf(components,gui);
	    }
	  if(tenum == 1)
	    {
	      efadd_label_cnf(components,gui);
	    }
	  if(tenum == 2)
	    {
	      efadd_text_box_cnf(components,gui);
	    }
	  if(tenum == 3)
	    {
	      efadd_picture_cnf(components,gui);
	    }
	  if(tenum == 4)
	    {
	      efadd_timer_cnf(components,gui);
	    }
	  i = i + 1;
	}
      div = bunny_configuration_next(div);
    }
  return (gui);
}
