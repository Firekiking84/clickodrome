#include		"timer.h"

void			efedit_timer(t_timer			*timer,
				     t_timer_settings const	*edit)
{
  timer->delay = edit->delay;
  efvector_ptr_delete(timer->functions);
  efvector_ptr_new_vector(edit->functions);
}
