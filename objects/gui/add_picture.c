#include "gui.h"

void			efadd_picture_gui(t_gui			*gui,
  				      t_zposition		pos,
				      t_bunny_size		size,
				      const char		*name,
				      const char		*filename)
{

    size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_picture_div(&efvector_at(gui->divs, count, t_div),pos
		       ,size ,name ,filename);
      count++;
    }
}
