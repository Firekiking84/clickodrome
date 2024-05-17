/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 17/05/2024 11:28:17 ******************************************************
** keryan.houssin <keryan.houssin@gagarine.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"calculator.h"

void			calculate(t_calculator	*cal)
{
  if (cal->operator == NONE)
    cal->res = cal->buffer;
  else if (cal->operator == ADD)
    cal->res += cal->buffer;
  else if (cal->operator == SUBSTRACT)
    cal->res -= cal->buffer;
  else if (cal->operator == MULTIPLY)
    cal->res *= cal->buffer;
  else if (cal->operator == DIVIDE && cal->buffer != 0)
    cal->res /= cal->buffer;
  else if (cal->operator == MODULO && cal->buffer != 0)
    cal->res = ((int)cal->res) % ((int)cal->buffer);
  cal->buffer = 0;
  update_string(cal);
}
