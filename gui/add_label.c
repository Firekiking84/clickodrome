#include "gui.h"

void			efadd_label_gui(t_gui			*gui,
					t_zposition     	pos,
					t_bunny_size		size,
					const char		*name,
			   		const char		*text,
					t_bunny_color		*font_color,
					t_bunny_color		*bg)
{
    size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_label_div(&efvector_at(gui->divs, count, t_div),pos ,size ,name ,text ,font_color ,bg);
      count++;
    }
}
