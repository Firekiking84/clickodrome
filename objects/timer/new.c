/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 14/05/2024 16:25:19 ******************************************************
** kenan.guidat <kenan.guidat@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	"timer.h"

t_timer         *efnew_timer(t_timer_settings	*settings)
{
  t_timer	*time;

  if ((time = bunny_malloc(sizeof(t_timer))) == NULL)
    {
      perror(" bunny_malloc new_timer");
      return (NULL);
    }
  time->gui = settings->gui;
  time->name = settings->name;
  time->last_time = 0;
  if (settings->delay < 0)
    {
      dprintf(2, "Wrong delay value. Set to default(1)");
      time->delay = 1;
    }
  else
    time->delay = settings->delay;
  time->lib = settings->lib;
  time->functions = settings->functions;
  return (time);
}
