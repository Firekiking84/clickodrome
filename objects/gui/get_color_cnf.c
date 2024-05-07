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
  int		tmp;

  color = bunny_malloc(sizeof(t_bunny_color));
  if (!color)
    return(NULL);
  color->argb[ALPHA_CMP] = 255;
  bunny_configuration_getf_int(cnf, &tmp, "components.%s[0]", name);
  if (tmp <= 255 && tmp >= 0)
    color->argb[RED_CMP] = tmp;
  else
    color->argb[RED_CMP] = 255;
  bunny_configuration_getf_int(cnf, &tmp, "components.%s[1]", name);
  if (tmp <= 255 && tmp >= 0)
    color->argb[GREEN_CMP] = tmp;
  else
    color->argb[GREEN_CMP] = 255;
  bunny_configuration_getf_int(cnf, &tmp, "components.%s[2]", name);
  if (tmp <= 255 && tmp >= 0)
    color->argb[BLUE_CMP] = tmp;
  else
    color->argb[BLUE_CMP] = 255;
  return (color);
}
