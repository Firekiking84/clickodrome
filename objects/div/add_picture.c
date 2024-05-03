#include	"div.h"

t_picture	*efadd_picture_div(t_div				*div,
				   t_picture_settings		*settings)
{
  t_picture	*picture;

  if (!efcheck_pos_new_component(div->pos, div->end_pos, &settings->pos, &settings->size))
    return(NULL);
  picture = efnew_picture(settings);
  if (!picture)
    return(NULL);
  efvector_ptr_push(div->pictures, picture);
  return (picture);
}
