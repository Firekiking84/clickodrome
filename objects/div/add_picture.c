#include "div.h"

t_picture			*efadd_picture_div(t_div				*div,
						  t_picture_settings		*settings)
{
  t_picture	 *picture;

  picture = efnew_picture(settings);
  if (!picture)
    return(NULL);
  efvector_ptr_push(div->pictures, picture);
  return (picture);
}
