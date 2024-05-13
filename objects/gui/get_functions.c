/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:44:15 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

t_vector_ptr		*efget_functions(t_bunny_configuration		*cnf,
					 t_gui				*gui)
{
  int			i;
  int			j;
  t_lib			*lib;
  t_div			*current_div;
  t_vector_ptr		*functions;
  const char		*func_name;
  void			*func_ptr;

  j = bunny_configuration_casesf(cnf, "components.functions");
  if (!(functions = efvector_ptr_new(j)))
    return(NULL);
  current_div = efvector_ptr_get(gui->divs, gui->divs->data_count - 1);
  lib = current_div->lib;
  i = 0;
  while (i < j)
    {
      bunny_configuration_getf(cnf, &func_name, "components.functions[%d]", i);
      func_ptr = dlsym(lib->link, func_name);
      efvector_ptr_push(functions, &func_ptr);
      i++;
    }
  return(functions);
}
