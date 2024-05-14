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

void operation(t_gui gui ,void *data)
{
  if (data->operator == ADD)
    {
      data->res = data->res + buffer;
    }
  if (data->operator == SUBTRACT)
    {
      data->res = data->res - buffer;
    }
  if (data->operator == MULTIPLY)
    {
      data->res = data->res * buffer;
    }
  if (data->operator == DIVIDE)
    {
      data->res = data->res / buffer;
    }
  if (data->operator == MODULO)
    {
      data->res = data->res % buffer;
    }
  update_string(t_gui gui ,void *data);
  data->operator = NONE;
  return(void);
}
