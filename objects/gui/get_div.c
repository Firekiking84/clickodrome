/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:43:50 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

#include		<string.h>
#include		<stdio.h>

static t_lib		*lib_already_load(const char		*divname,
					  t_gui			*gui)
{
  size_t		i;
  t_lib			*lib;

  i = 0;
  while (i < gui->libs->data_count)
    {
      lib = efvector_ptr_get(gui->libs, i);
      if (strcmp(divname, lib->name) == 0)
	return(lib);
      i += 1;
    }
  return(NULL);
}

static void		*short_return(const char		*err_msg,
				      t_lib			*lib,
				      int			mode)
{
  if (mode == -1)
    return(lib);
  bunny_perror(err_msg);
  if (mode >= 1)
    bunny_free(lib);
  if (mode >= 2)
    bunny_free(lib->name);
  return(NULL);
}

static t_lib		*get_lib_cnf(t_bunny_configuration	*cnf,
				     t_gui			*gui,
				     char			*divname)
{
  const char		*tmp;
  t_lib			*lib;
  void			*(*init_func)();

  if (!bunny_configuration_getf(cnf, &tmp, "lib"))
    return(short_return("lib div", NULL, 0));
  lib = lib_already_load(tmp, gui);
  if (lib)
    return(lib);
  lib = bunny_malloc(sizeof(t_lib));
  if (!lib)
    return(short_return("malloc lib", NULL, 0));
  lib->name = bunny_malloc(sizeof(char) * (strlen(tmp) + 1));
  if (!lib->name)
    return(short_return("malloc lib name", lib, 1));
  strcpy(lib->name, tmp);
  lib->div_name = divname;
  lib->link = dlopen(lib->name, RTLD_LAZY);
  if (!lib->link)
    return(short_return("error dlopen", lib, 2));
  if (!bunny_configuration_getf(cnf, &tmp, "init_func"))
    return(short_return("cannot get init_struct", lib, 2));
  init_func = dlsym(lib->link, tmp);
  if (!init_func)
    return(short_return("cannot link init_func", lib, 2));
  lib->data = init_func();
  return(lib);
}

t_div			*efget_div_cnf(t_bunny_configuration	*cnf,
				       t_gui			*gui)
{
  t_div			*tdiv;
  const char		*tmp;
  char			*divname;
  t_bunny_size		size;
  t_bunny_position	pos;
  t_lib			*lib;

  tmp = bunny_configuration_get_name(cnf);
  divname = efstrdup(tmp);
  pos = efget_pos_cnf(cnf);
  if (pos.x == -1)
    return(NULL);
  size = efget_size_cnf(cnf, "size");
  lib = get_lib_cnf(cnf, gui, divname);
  tdiv = efnew_div(divname, pos, size, lib);
  return(tdiv);
}
