#ifndef			__TIMER_H__

#define			__TIMER_H__

#include		<stddef.h>
#include		"vector_ptr.h"

typedef struct		s_timer_settings
{
  char			*name;
  size_t		delay;
  t_vector_ptr		*functions;
}			t_timer_settings;

typedef struct	        s_timer
{
  size_t		last_time;
  size_t		delay;
  char			*name;
  t_vector_ptr		*functions;
}			t_timer;

t_timer		*efnew_timer(t_timer_settings			*settings);
void		efdelete_timer(t_timer				*timer);
void		efrefresh_timer(t_timer				*timer);


#endif	//		__TIMER_H__
