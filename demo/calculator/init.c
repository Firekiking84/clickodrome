/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 07/05/2024 13:10:22 ******************************************************
** romain.cescutti <romain.cescutti@aldrin.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	"calculator.h"
#include	<lapin.h>

t_calculator	*init_calculator(void)
{
  t_calculator	*calculator;

  calculator = bunny_malloc(sizeof(*calculator));
  if (!calculator)
    return(NULL);
  calculator->res = 0;
  calculator->buffer = 0;
  calculator->operator = NONE;
  calculator->string = efstring_new();
  return(calculator);
}
