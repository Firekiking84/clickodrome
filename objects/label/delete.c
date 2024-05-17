/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 14/05/2024 16:30:46 ******************************************************
** kenan.guidat <kenan.guidat@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"label.h"

void                    efdelete_label(t_label                  *label)
{
  if (label == NULL)
    return;
  bunny_free(label->name);
  bunny_free(label->text);
  bunny_delete_clipable(&label->font->clipable);
  bunny_free(label->font_color);
  bunny_free(label->bg);
  bunny_free(label);
}
