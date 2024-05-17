/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:43:16 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

void			efdelete_gui(t_gui	*gui)
{
  size_t		i;
  t_lib			*lib;
  t_font		*font;

  i = 0;
  while (i < gui->libs->data_count)
    {
      lib = efvector_ptr_get(gui->libs, i);
      bunny_free(lib->name);
      dlclose(lib->link);
      i += 1;
    }
  efvector_ptr_delete(gui->libs);
  efvector_ptr_delete(gui->components);
  i = 0;
  while (i < gui->divs->data_count)
    {
      efdelete_div(efvector_ptr_get(gui->divs, i));
      i += 1;
    }
  efvector_ptr_delete(gui->divs);
  i = 0;
  while (i < gui->fonts->data_count)
    {
      font = efvector_ptr_get(gui->fonts, i);
      bunny_free(font->name);
      bunny_delete_clipable(&font->px->clipable);
      i += 1;
    }
  efvector_ptr_delete(gui->fonts);
}
