#ifndef			__LABEL_H__

#define			__LABEL_H__

#include		"draw.h"

typedef struct	        s_label
{
  t_bunny_position	pos;
  t_bunny_position	pos_end;
  t_bunny_size		size;
  char			*name;
  char			*text;
  t_bunny_pixelarray	*font;
  t_bunny_size		font_size;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
}			t_label;

typedef struct		s_label_settings
{
  t_bunny_position	       	pos;
  t_bunny_size		size;
  char			*name;
  char			*text;
  char			*font_name;
  t_bunny_pixelarray	*font_res;
  t_bunny_size		font_size;
  t_bunny_color		*font_color;
  t_bunny_color	        *bg;
}			t_label_settings;

t_label			*efnew_label(t_label_settings		*set);
void			efdisplay_label(t_label			*label,
					t_bunny_pixelarray	*px);
void			efdelete_label(t_label			*label);
void			efedit_label(t_label			*label,
				     t_label_settings const	*edit);


#endif	//		__LABEL_H__
