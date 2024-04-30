/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 30/04/2024 15:59:27 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"text_box.h"

#include		<stdio.h>

void			erase_selection(t_text_box			*box)
{
  int			i;
  int			start;
  int			range;

  if (!box->selection_active)
    return;
  if (box->selected_area.start < box->selected_area.end)
    {
      start = box->selected_area.start;
      range = box->selected_area.end - start;
    }
  else
    {
      start = box->selected_area.end;
      range = box->selected_area.start - start;
    }
  i = 0;
  while (i < range)
    {
      string_erase(box->text, start);
      i += 1;
    }
}
