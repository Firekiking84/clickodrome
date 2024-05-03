/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 30/04/2024 15:59:41 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"text_box.h"

void			efdelete_text_box(t_text_box	*text_box)
{
  free(text_box->name);
  string_delete(text_box->text);
  string_delete(text_box->copy);
  if (text_box->bg)
    free(text_box->bg);
  if (text_box->font_color)
    free(text_box->font_color);
  efvector_ptr_delete(text_box->functions);
  free(text_box);
}
