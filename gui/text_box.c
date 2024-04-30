#include "gui.h"

void			efadd_text_box_gui(t_gui		*gui,
				       t_zposition		pos,
				       t_bunny_size		size,
				       const char		*name,
				       t_bunny_color		*font_color,
				       t_bunny_color		*bg,
				       t_vector			*functions)
{
   size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_text_box_div(&efvector_at(gui->divs, count, t_div),pos
			 ,size,name ,font_color,bg ,functions);
      count++;
    }
}
