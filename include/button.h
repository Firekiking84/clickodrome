#ifndef			__BUTTON_H__

#define			__BUTTON_H__

#include		"button.h"
#include		"lapin.h"
#include		"draw.h"
#include		"vector_ptr.h"
#include		"lib.h"

#include		<stddef.h>
#include		<stdlib.h>

struct s_gui;

typedef struct	        s_button
{
  struct s_gui		*gui;
  t_bunny_position	pos;
  t_bunny_size		size;
  char			*text;
  char			*name;
  bool			in_button;
  bool			focus;
  t_bunny_color		*hover_color;
  t_bunny_color		*font_color;
  t_bunny_pixelarray	*font;
  t_bunny_size		font_size;
  t_bunny_color		*bg;
  t_lib			*lib;
  t_vector_ptr		*functions;
}			t_button;

typedef struct		s_button_settings
{
  struct s_gui		*gui;
  t_bunny_position	pos;
  t_bunny_size		size;
  char			*name;
  char			*text;
  char			*font;
  t_bunny_size		font_size;
  t_bunny_color		*font_color;
  t_bunny_color		*hover_color;
  t_bunny_color		*bg;
  t_lib			*lib;
  t_vector_ptr		*functions;
}			t_button_settings;


t_button		*efnew_button(t_button_settings *set);
void			efdelete_button(t_button		*button);
t_button		*efnew_button(t_button_settings		*set);
void			efdisplay_button(t_button		*button,
					 t_bunny_pixelarray	*px);
void			efevent_button(t_button		    	*button,
					t_bunny_event const	*event);
void			efedit_button(t_button			*button,
				      t_button_settings const	*edit);

#endif	//		__BUTTON_H__              //
