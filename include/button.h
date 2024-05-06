#ifndef			__BUTTON_H__

#define			__BUTTON_H__

#include "button.h"
#include "vector.h"
#include "lapin.h"
#include "draw.h"
#include "vector_ptr.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	        s_button
{
  t_zposition		pos;
  t_bunny_size		size;
  char			*text;
  char			*name;
  bool			in_button;
  bool			focus;
  t_bunny_color		*hover_color;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
  t_vector_ptr		*functions;
}			t_button;

typedef struct		s_button_settings
{
  t_zposition		pos;
  t_bunny_size		size;
  char			*name;
  char			*text;
  char			*font;
  t_bunny_size		font_size;
  t_bunny_color		*font_color;
  t_bunny_color		*hover_color;
  t_bunny_color		*bg;
  t_vector_ptr		*function;
}			t_button_settings;

t_button		*efnew_button(t_button_settings		*set);
size_t			efdelete_button(t_button		*button);
void			efdisplay_button(t_button		*button,
					 t_bunny_zpixelarray	*px);
void			efevents_button(t_button	    	*button,
					t_bunny_event const	*event);
void			efedit_button(t_button			*button,
				      t_button_settings		*edit);
#endif	//		__BUTTON_H__              //
