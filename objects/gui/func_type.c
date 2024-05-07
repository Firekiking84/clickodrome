/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:43:33 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	"gui.h"

void		eftype_func(t_bunny_configuration	*comp,
			    t_gui			*gui,
			    int				i)
{
  const char	*type;
  int		tenum;

  bunny_configuration_getf(comp, &type, "components[%d].type", i);
  tenum = efcomp_type(type);
  if(tenum == BUTTON)
    efadd_button_cnf(comp, gui);
  if(tenum == LABEL)
    efadd_label_cnf(comp, gui);
  if(tenum == TEXTBOX)
    efadd_text_box_cnf(comp, gui);
  if(tenum == PICTURE)
    efadd_picture_cnf(comp, gui);
  if(tenum == TIMER)
    efadd_timer_cnf(comp, gui);
}
