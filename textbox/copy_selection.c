/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 30/04/2024 16:00:18 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"text_box.h"

void			copy_selection(t_text_box			*box)
{
  int			i;
  int			end;

  if (!box->selection_active)
    return;
  if (box->selected_area.start < box->selected_area.end)
    {
      i = box->selected_area.start;
      end = box->selected_area.end;
    }
  else
    {
      i = box->selected_area.end;
      end = box->selected_area.start;
    }
  string_clear(box->copy);
  while (i < end)
    {
      string_push_back(box->copy, string_get_char(box->text, i));
      i += 1;
    }
}
