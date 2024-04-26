#include "gui.h"
void			efadd_button_gui(t_gui			*gui,
				     const char			*name,
				     t_zposition		pos,
				     t_bunny_size		size,
				     const char			*text,
				     t_bunny_color		*font_color,
				     t_bunny_color		*hover_color,
				     t_bunny_color		*bg,
				     t_vector		        *functions)
{
  size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efadd_button_div(efvecteur_at(gui->divs, count, t_div),pos
		       ,name ,size ,text ,font_color,hover_color ,bg ,functions);
      count++;
    }
}
