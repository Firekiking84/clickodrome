#ifndef			__TIMER_H__

#define			__TIMER_H__

#include		<stddef.h>
#include		<lapin.h>

#include		"vector_ptr.h"
#include		"lib.h"

struct s_gui;

typedef struct		s_timer_settings
{
  struct s_gui		*gui;
  char			*name;
  ssize_t		delay;
  t_lib			*lib;
  t_vector_ptr		*functions;
}			t_timer_settings;

typedef struct	        s_timer
{
  struct s_gui		*gui;
  size_t		last_time;
  size_t		delay;
  char			*name;
  t_lib			*lib;
  t_vector_ptr		*functions;
}			t_timer;

t_timer		*efnew_timer(t_timer_settings			*settings);
void		efdelete_timer(t_timer				*timer);
void		efrefresh_timer(t_timer				*timer);
void		efedit_timer(t_timer				*timer,
			     t_timer_settings const		*edit);

#endif	//		__TIMER_H__
