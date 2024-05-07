#include		"div.h"

void			efrefresh_div(t_div			*div)
{
  size_t		i;

  i = 0;
  while(i < div->timers->data_count)
    {
      efrefresh_timer(efvector_ptr_get(div->timers, i));
      i ++;
    }
}
