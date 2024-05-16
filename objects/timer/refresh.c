/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 14/05/2024 16:24:56 ******************************************************
** kenan.guidat <kenan.guidat@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"

void            efrefresh_timer(t_timer                         *timer)
{
  double	time;
  size_t	i;

  i = 0;
  time = bunny_get_current_time() * 1000;
  if (time - timer->delay >= timer->last_time)
    {
      while (i < timer->functions->data_count)
	{
	  ((void (*)(t_gui *, void *))efvector_ptr_get(timer->functions, 0))(timer->gui, timer->lib->data);
	  i++;
	}
      timer->last_time = time;
    }
}
