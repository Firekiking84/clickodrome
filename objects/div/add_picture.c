#include "div.h"

void			efadd_picture_div(t_div			*div,
					  t_picture_settings	*settings)
{
  efvector_push (div->pictures, efnew_picture(settings));
}
