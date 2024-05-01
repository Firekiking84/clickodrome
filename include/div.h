#ifndef		__DIV_H__

#define		__DIV_H__

#include	"vector.h"
#include        "draw.h"
#include        "picture.h"
#include        "text_box.h"
#include        "button.h"
#include        "label.h"
#include        "timer.h"

#include	<lapin.h>

typedef struct		s_div
{
  const char		*name;
  t_zposition	        pos;  // pos top left
  t_bunny_size		size;
  t_vector		*labels;
  t_vector		*buttons;
  t_vector		*text_boxes;
  t_vector		*pictures;
  t_vector		*timer;
}			t_div;

t_div			*efnew_div(const char			*name,
				   t_zposition		        pos,
				   t_bunny_size			size);
size_t			efdelete_div(t_div			*div);
void			efdisplay_div(t_div			*div,
				      t_bunny_pixelarray	*px);
void			efadd_button_div(t_div			*div,
				     t_zposition		pos,
				     t_bunny_size		size,
				     const char	        	*name,
				     const char			*text,
				     t_bunny_color		*font_color,
				     t_bunny_color		*hover_color,
				     t_bunny_color		*bg,
				     t_vector		        *functions);
void			efadd_label_div(t_div	 		*div,
				    t_zposition	        	pos,
				    t_bunny_size		size,
				    const char			*name,
				    const char			*text,
				    t_bunny_color		*font_scolor,
				    t_bunny_color		*bg);
void			efadd_text_box_div(t_div		*div,
				       t_zposition		pos,
				       t_bunny_size		size,
				       const char		*name,
				       t_bunny_color		*font_color,
				       t_bunny_color		*bg,
				       t_vector			*functions);
void			efadd_picture_div(t_div			*div,
				      t_zposition		pos,
				      t_bunny_size		size,
				      const char		*name,
				      const char		*filename);
void			efadd_timer_div(t_div			*div,
				    const char			*name,
				    int                         delay,
				    t_vector			*functions);
void                    efevents_div(t_div                      *div,
				     const t_bunny_event        *event);
void			efrefresh_div(t_div			*div);
#endif //	__DIV_H__
