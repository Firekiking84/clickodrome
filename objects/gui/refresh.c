#include	"gui.h"

void		efrefresh_gui(t_gui			*gui)
{
  size_t	count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      efrefresh_div(efvector_ptr_get(gui->divs, count));
      count ++;
    }
}
