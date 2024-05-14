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
			    t_gui			*gui)
{
  const char	*type;
  int		tenum;

  if (bunny_configuration_getf(comp, &type, "type")== false)
    write(1, "type manquant dans le .dab\n", 28);
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
