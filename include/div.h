#ifndef		__DIV_H__

#define		__DIV_H__

#include	"vector_ptr.h"
#include        "draw.h"
#include        "picture.h"
#include        "text_box.h"
#include        "button.h"
#include        "label.h"
#include        "timer.h"

#include	<lapin.h>

typedef struct			s_div
{
  const char			*name;
  t_bunny_position		pos;  // pos top left
  t_bunny_size			size;
  bool				in_div;
  t_bunny_position		end_pos;
  t_vector_ptr			*labels;
  t_vector_ptr			*buttons;
  t_vector_ptr			*text_boxes;
  t_vector_ptr			*pictures;
  t_vector_ptr			*timers;
}				t_div;


t_div				*efnew_div(const char				*name,
					   t_bunny_position			pos,
					   t_bunny_size				size);
void				efdelete_div(t_div				*div);
void				efrefresh_div(t_div				*div);
void				efdisplay_div(t_div				*div,
					      t_bunny_zpixelarray		*px);
t_button			*efadd_button_div(t_div				*div,
						 t_button_settings		*set);
t_label				*efadd_label_div(t_div				*div,
						t_label_settings		*set);
t_text_box   			*efadd_text_box_div(t_div			*div,
						   t_textbox_settings		*set);
t_picture			*efadd_picture_div(t_div			*div,
						  t_picture_settings		*set);
t_timer				*efadd_timer_div(t_div				*div,
						t_timer_settings		*set);
void			        efevents_div(t_div				*div,
					     const t_bunny_event		*event);
bool				efcheck_pos_new_component(t_div			*div,
							  t_zposition		*pos,
							  t_bunny_size		*size);
void				efedit_button_div(t_div				*div,
						  t_button_settings const	*edit);
void				efedit_label_div(t_div				*div,
						 t_label_settings const		*edit);
void				efedit_textbox_div(t_div			*div,
						   t_textbox_settings const	*edit);
void				efedit_picture_div(t_div			*div,
						   t_picture_settings const	*edit);
void				efedit_timer_div(t_div				*div,
						 t_timer_settings const		*edit);

#endif //	__DIV_H__		//
