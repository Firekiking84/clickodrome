#include	"gui.h"

t_bunny_color	*efget_color_cnf(t_bunny_configuration	*cnf,
				char			*name)
{
  t_bunny_color *color;
  color = bunny_malloc(sizeof(t_bunny_color));
  int temp;
  int temp2;

  temp = 0;
  temp2 = 0;

  bunny_configuration_getf_int(cnf,&temp, "components.%s[0]", name);
  temp2 += temp;
  bunny_configuration_getf_int(cnf,&temp, "components.%s[1]", name);
  temp2 += temp * 256;
  bunny_configuration_getf_int(cnf,&temp, "components.%s[2]", name);
  temp2 += temp * 256 * 256;
  color->full = temp2;
  return (color);
}
