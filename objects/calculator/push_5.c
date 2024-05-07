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

void push_5	(t_gui gui ,void *data)
{
  data->buffer = 5;
  if (data->operator == NONE)
    {
      if (data->res != 0)
	{
	  data->res = data->res * 10;
	  res += buffer;
	}
      string_push_back(data->string,'5');
    }
  if (data->operator != NONE)
    {
      operation(gui,data,buffer);
    }
  return(void);
}
