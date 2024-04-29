#ifndef			__TEXT_BOX_H__

#define			__TEXT_BOX_H__

#include		"efstring.h"
#include		"vector.h"
#include		"draw.h"

#include		<stddef.h>
#include		<lapin.h>

typedef struct	        s_text_box
{
  t_zposition		pos;
  t_bunny_size		size;
  char			*name;
  t_string		*text;
  bool			has_focus;
  bool			pressed_in;
  int			cursor_pos;
  t_bunny_size		size_font;
  int			max_letter_on_line;
  int			max_nb_lines;
  int			max_letter;
  t_bunny_pixelarray	*font;
  t_bunny_color		font_color;
  t_bunny_color		*bg;
  t_vector		*functions;
  double		time_cursor_blink;
}			t_text_box;

t_text_box		*efnew_text_box(t_zposition		pos,
					t_bunny_size		size,
					const char		*name,
					t_bunny_color		font_color,
					t_bunny_color		*bg,
					t_vector		*functions);
void			efdelete_text_box(t_text_box		*text_box);
void			efdisplay_text_box(t_text_box		*text_box,
					   t_bunny_zpixelarray	*px);
void			efevent_text_box(t_text_box		*text_box,
					 const t_bunny_event	*event);
int			mult_arrondi(int			x,
				     int			mult,
				     int			mode); // -1 inférieur 0 au plus proche 1 au supérieur


#endif	//		__TEXT_BOX_H__
