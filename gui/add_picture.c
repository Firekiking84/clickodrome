#include "gui.h"

void			efadd_picture_gui(t_gui			*gui,
				      const char		*name,
				      t_bunny_position		pos,
				      t_bunny_size		size,
				      const char		*filename)
{

    size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_picture(efvector_at(gui->divs, count, t_div),pos
		       ,name ,size ,filename);
      count++;
    }
}
