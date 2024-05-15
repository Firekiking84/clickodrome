/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 07/05/2024 11:59:18 ******************************************************
** romain.cescutti <romain.cescutti@aldrin.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include "calculator.h"

void push_4	(t_gui *gui ,void *data)
{
  t_calculator *calc;
  calc = data;
  calc->buffer = 4;
  if (calc->operator == NONE)
    {
      if (calc->res != 0)
	{
	  calc->res = calc->res * 10;
	  calc->res += calc->buffer;
	}
      string_push_back(calc->string,'4');
    }
  if (calc->operator != NONE)
    {
      operation(gui,data);
    }
}
