#ifndef			__LABEL_H__

#define			__LABEL_H__

#include		"draw.h"

typedef struct	        s_label
{
  t_zposition		*pos;
  t_bunny_size		size;
  char			*name;
  char			*text;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
}			t_label;

typedef struct		s_label_settings
{
  t_zposition	       	pos;
  char			*name;
  t_bunny_size		size;
  char			*text;
  t_bunny_color		*font_color;
  t_bunny_color	        *bg;
}			t_label_settings;

t_label			*efnew_label(t_label_settings		*set);
void			efdisplay_label(t_label			*label,
					t_bunny_zpixelarray	*px,
					t_bunny_pixelarray	*font);
void			efdelete_label(t_label			*label);


#endif	//		__LABEL_H__
