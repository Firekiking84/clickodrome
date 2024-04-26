#include "div.h"
void			efrefresh_div(t_div			*div)
{
  size_t i;

  i = 0;
  while(i < div->timer->data_count)
    {
      efcall_timer(efvector_at(div->timer, i , t_timer));
      i ++;
    }
}
