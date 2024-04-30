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
  const char		*text;
  const char		*name;
  t_zposition	        pos;
  t_bunny_size		size;
  bool			in_button;
  bool			focus;
  t_bunny_color		*hover_color;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
  t_vector		*functions;
}			t_button;
t_button		*efnew_button(
				      t_zposition		*pos,
				      t_bunny_size		size,
				      const char		*name,
				      const char		*text,
				      t_zposition		pos,
				      t_bunny_size		size,
				      bool			in_button,
				      bool			focus,
				      t_bunny_color		*hover_color,
				      t_bunny_color		*font_color,
				      t_bunny_color		*bg,
				      t_bunny_color             *hover_color,
				      t_vector			*function);
void			efdelete_button(t_button		*button);
void			efdisplay_button(t_button		*button,
					 t_bunny_zpixelarray	*px);
void			efevents_button(t_button	    	*button,
					t_bunny_event		*event);

#endif	//		__BUTTON_H__
