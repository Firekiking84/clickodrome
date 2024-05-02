#include	"gui.h"

void		efrefresh_gui(t_gui			*gui)
{
  size_t	count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efrefresh_div(&efvector_at(gui->divs, count, t_div));
      count ++;
    }
}
