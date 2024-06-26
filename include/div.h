#ifndef		__DIV_H__

#define		__DIV_H__

#include	"vector_ptr.h"
#include        "draw.h"
#include        "picture.h"
#include        "text_box.h"
#include        "button.h"
#include        "label.h"
#include        "timer.h"
#include	"lib.h"

#include	<lapin.h>

typedef struct			s_div
{
  char				*name;
  t_bunny_position		pos;  // pos top left
  t_bunny_size			size;
  t_bunny_position		end_pos;
  t_lib				*lib;
  bool				in_div;
  t_vector_ptr			*labels;
  t_vector_ptr			*buttons;
  t_vector_ptr			*text_boxes;
  t_vector_ptr			*pictures;
  t_vector_ptr			*timers;
}				t_div;

t_div				*efnew_div(char					*name,
					   t_bunny_position			pos,
					   t_bunny_size				size,
					   t_lib				*lib);
void				efdelete_div(t_div				*div);
void				efdelete_elem_div(t_div				*div,
						  const char			*elem_name);
bool				efdelete_label_div(t_div			*div,
						   const char			*elem_name);
bool				efdelete_button_div(t_div			*div,
						    const char			*elem_name);
bool				efdelete_textbox_div(t_div			*div,
						     const char			*elem_name);
bool				efdelete_picture_div(t_div			*div,
						     const char			*elem_name);
bool				efdelete_timer_div(t_div			*div,
						   const char			*elem_name);
void				efrefresh_div(t_div				*div);
void				efdisplay_div(t_div				*div,
					      t_bunny_pixelarray		*px);
t_button			*efadd_button_div(t_div				*div,
						  t_button_settings		*set);
t_label				*efadd_label_div(t_div				*div,
						 t_label_settings		*set);
t_text_box   			*efadd_textbox_div(t_div			*div,
						   t_textbox_settings		*set);
t_picture			*efadd_picture_div(t_div			*div,
						   t_picture_settings		*set);
t_timer				*efadd_timer_div(t_div				*div,
						 t_timer_settings		*set);
int			        efevent_div(t_div				*div,
					    const t_bunny_event			*event);
bool				efcheck_pos_new_component(t_div			*div,
							  t_bunny_position	*pos,
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
