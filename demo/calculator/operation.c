/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 17/05/2024 12:09:04 ******************************************************
** keryan.houssin <keryan.houssin@gagarine.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	"calculator.h"

void		operation(t_gui		*gui,
			  void		*data)
{
  t_calculator	*calc;

  calc = data;
  if (calc->operator == ADD)
    calc->res += calc->buffer;
  else if (calc->operator == SUBSTRACT)
    calc->res -= calc->buffer;
  else if (calc->operator == MULTIPLY)
    calc->res *= calc->buffer;
  else if (calc->operator == DIVIDE)
    {
      if (calc->buffer != 0)
	calc->res = calc->res / calc->buffer;
    }
  else if (calc->operator == MODULO && calc->buffer != 0)
    calc->res = ((int)calc->res) % ((int)calc->buffer);
  calc->buffer = calc->res;
  calc->res = 0;
  update_string(calc);
  calc->operator = NONE;
}
