/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:43:38 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include	"gui.h"

t_bunny_color	*efget_color_cnf(t_bunny_configuration	*cnf,
				char			*name)
{
  t_bunny_color *color;

  color = bunny_malloc(sizeof(t_bunny_color));
  if (!color)
    return(NULL);
  color.argb[ALPHA_CMP] = 255;
  bunny_configuration_getf_int(cnf, &color.argb[RED_CMP], "components.%s[0]", name);
  bunny_configuration_getf_int(cnf, &color.argb[GREEN_CMP], "components.%s[1]", name);
  bunny_configuration_getf_int(cnf, &color.argb[BLUE_CMP], "components.%s[2]", name);
  return (color);
}
