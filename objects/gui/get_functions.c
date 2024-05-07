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
  void			*link;
  t_vector_ptr		*functions;
  void			*func_ptr;
  const char		*func;
  const char		*lib;

  j = bunny_configuration_casesf(cnf, "components.functions");
  if (j > 0)
    {
      bunny_configuration_getf(cnf, &lib, "components.functions[0]");
      link = dlopen(lib,  RTLD_NOW); // lib needs to contain path to the library
      efvector_ptr_push(gui->libs, link);
    }
  if (!(functions = efvector_ptr_new(j)))
    return(NULL);
  i = 1;
  while (i < j)
    {
      bunny_configuration_getf(cnf, &func, "components.functions[%d]", i);
      func_ptr = dlsym(link, func);
      efvector_ptr_push(functions, &func_ptr);
      i++;
    }
  return(functions);
}
