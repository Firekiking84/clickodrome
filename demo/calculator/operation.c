/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 07/05/2024 12:43:09 ******************************************************
** romain.cescutti <romain.cescutti@aldrin.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include "calculator.h"

void operation(t_gui *gui ,void *data)
{
  t_calculator *calc;
  calc = data;
  if (calc->operator == ADD)
    {
      calc->res = calc->res + calc->buffer;
    }
  if (calc->operator == SUBSTRACT)
    {
      calc->res = calc->res - calc->buffer;
    }
  if (calc->operator == MULTIPLY)
    {
      calc->res = calc->res * calc->buffer;
    }
  if (calc->operator == DIVIDE)
    {
      calc->res = calc->res / calc->buffer;
    }
  if (calc->operator == MODULO)
    {
      calc->res = fmod(calc->res,calc->buffer);
    }
  update_string(gui , data);
  calc->operator = NONE;
}
