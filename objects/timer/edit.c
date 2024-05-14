/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 14/05/2024 16:25:30 ******************************************************
** kenan.guidat <kenan.guidat@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"timer.h"

void			efedit_timer(t_timer			*timer,
				     t_timer_settings const	*edit)
{
  if (edit->delay >= 0)
    timer->delay = edit->delay;
  if (edit->functions)
    {
      efvector_ptr_delete(timer->functions);
      efvector_ptr_new_vector(edit->functions);
    }
}
