/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 17/05/2024 11:12:19 ******************************************************
** keryan.houssin <keryan.houssin@gagarine.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"calculator.h"

static void		init_label_settings(t_label_settings	*set)
{
  set->pos.x = -1;
  set->pos.y = -1;
  set->size.x = -1;
  set->size.y = -1;
  set->name = efstrdup("screen");
  set->text = NULL;
  set->font_name = NULL;
  set->font_res = NULL;
  set->font_size.x = -1;
  set->font_size.y = -1;
  set->font_color = NULL;
  set->bg = NULL;
}

void			push(t_gui				*gui,
			     t_calculator			*cal,
			     int				value)
{
  t_label_settings	set;

  if (value == 0 && cal->buffer == 0)
    return;
  init_label_settings(&set);
  cal->buffer *= 10;
  cal->buffer += value;
  update_string(cal);
  set.text = cal->string->str;
  efedit_label_gui(gui, "calculator", &set);
  bunny_free(set.name);
}
