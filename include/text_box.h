/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 30/04/2024 16:35:40 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef			__TEXT_BOX_H__

#define			__TEXT_BOX_H__

#include		"efstring.h"
#include		"vector_ptr.h"
#include		"draw.h"

#include		<stddef.h>
#include		<lapin.h>

typedef struct		s_textbox_settings
{
  t_bunny_position	pos;
  t_bunny_size		size;
  char			*name;
  char			*font;
  t_bunny_size		font_size;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
  t_vector_ptr		*functions;
}			t_textbox_settings;

typedef struct		s_display_values
{
  int			start;
  int			i;
  int			n_line;
  int			n_letter;
}			t_display_values;

typedef struct		s_area
{
  int			start;
  int			end;
}			t_area;

typedef struct	        s_text_box
{
  t_bunny_position	pos;
  t_bunny_size		size;
  char			*name;
  t_string		*text;
  t_string		*copy;
  bool			has_focus;
  bool			pressed_in;
  int			cursor_pos;
  bool			selection_active;
  t_area		selected_area;
  t_bunny_size		size_font;
  int			max_letter_on_line;
  int			max_nb_lines;
  int			max_letter;
  t_bunny_pixelarray	*font;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
  t_vector_ptr		*functions;
  double		time_cursor_blink;
}			t_text_box;

t_text_box		*efnew_text_box(t_textbox_settings		*settings);
void			efdelete_text_box(t_text_box			*text_box);
void			efdisplay_text_box(t_text_box			*text_box,
					   t_bunny_pixelarray		*px);
void			efevent_text_box(t_text_box			*text_box,
					 const t_bunny_event		*event);
int			mult_arrondi(int				x,
				     int				mult,
				     int				mode); // -1 inférieur 0 au plus proche 1 au supérieur
void			erase_selection(t_text_box			*box);
void			copy_selection(t_text_box			*box);
void			paste(t_text_box				*box);
void			cut_selection(t_text_box			*box);
void			draw_cursor(t_text_box				*text_box,
				    t_bunny_position			draw_pos,
				    t_bunny_pixelarray			*px);
void			draw_bg(t_text_box				*text_box,
				t_bunny_pixelarray			*px);
void			draw_selected_area(t_text_box			*text_box,
					   t_bunny_position		pos_start,
					   t_bunny_pixelarray		*px);
int			get_cursor_pos(int				x,
				       int				y,
				       t_text_box			*box);
bool			check_mouse_button(t_text_box			*text_box,
					   t_bunny_mouse_button_event	mouse);
bool			manage_mouse_button_event(t_text_box		*text_box,
						  const t_bunny_event	*event);
bool			manage_text_event(t_text_box			*text_box,
					  const t_bunny_event		*event);
void			manage_key_event(t_text_box			*text_box,
					 const t_bunny_event		*event);
void			manage_solo_key(t_text_box			*text_box,
					const t_bunny_event		*event);
void			manage_control_key(t_text_box			*text_box,
					   const t_bunny_event		*event);
void			manage_shift_key(t_text_box			*text_box,
					 const t_bunny_event		*event);
void			efedit_textbox(t_text_box			*textbox,
				       t_textbox_settings		*edit);

#endif	//		__TEXT_BOX_H__
