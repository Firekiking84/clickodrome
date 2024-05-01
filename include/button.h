#ifndef			__BUTTON_H__

#define			__BUTTON_H__

#include		"vector.h"
#include		"draw.h"
#include		<stdio.h>
#include		<stdbool.h>
#include		<unistd.h>
#include		<lapin.h>

typedef struct	        s_button
{
  t_bunny_size		size;
  const char		*text;
  const char		*name;
  bool			in_button;
  bool			focus;
  t_bunny_color		*hover_color;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
  t_vector		*functions;
}			t_button;

typedef struct		s_settings_button
{
  t_zposition		*pos;
  t_bunny_size		size;
  const char		*name;
  const char		*text;
  t_bunny_color		*font_color;
  t_bunny_color		*hover_color;
  t_bunny_color		*bg;
  t_vector		*function;
}t_settings_button;

t_button		*efnew_button(t_settings_button *set);
size_t			efdelete_button(t_button		*button);
void			efdisplay_button(t_button		*button,
					 t_bunny_zpixelarray	*px);
void			efevents_button(t_button	    	*button,
					t_bunny_event const		*event);
#endif	//		__BUTTON_H__              //
