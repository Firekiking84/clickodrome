#ifndef			__LAB_H__

#define			__LAB_H__

#include		<lapin.h>

typedef struct          s_bunny_zpixelarray
{
  t_bunny_pixelarray    *px;
  double                *z;
}		        t_bunny_zpixelarray;

typedef struct		s_zposition
{
  int			x;
  int			y;
  double		z;
}			t_zposition;

typedef struct	        s_label
{
  t_zposition		pos;
  t_bunny_size		size;
  char			*name;
  char			*text;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
}			t_label;

typedef struct          s_program
{
  t_bunny_zpixelarray   *zpx;
  t_bunny_pixelarray	*font;
  t_bunny_window	*window;
}			t_program;

t_bunny_response        display_function(void                           *data);

t_bunny_response        loop_function(void                              *data);

t_label			*efnew_label(t_zposition		*pos,
				     t_bunny_size		size,
				     const char			*name,
				     const char			*text,
				     t_bunny_color		*font_color,
				     t_bunny_color		*bg);
void			efdisplay_label(t_label			*label,
					t_bunny_zpixelarray	*px,
					t_bunny_pixelarray	*font);
void			efdelete_label(t_label			*label);


void                    efclear_zbuffer(t_bunny_zpixelarray     *zpx);

void			set_pixel(t_bunny_pixelarray		*px,
				  t_bunny_position	        pos,
				  t_bunny_color			*col);
void			set_zpixel(t_bunny_zpixelarray		*px,
				   t_zposition			*pos,
				   t_bunny_color		*col);
void			draw_rectangle(t_bunny_zpixelarray	*px,
				       t_zposition		*posStart,
				       t_zposition		*posEnd,
				       t_bunny_color		*col);
void			blit(t_bunny_zpixelarray		*target,
			     const t_bunny_pixelarray		*src,
			     const t_zposition			*pos,
			     t_bunny_color			*forcedCol);
double			get_ratio(int				a,
				  int				b,
				  int				x);
int			get_value(int				a,
				  int				b,
				  double			ratio);
int			get_npos(int				width,
				 t_bunny_position		pos);

void			efletter(t_bunny_zpixelarray		*pix,
				 t_bunny_pixelarray		*font,
				 t_zposition			*pos,
				 t_bunny_color                  *col,
				 char				c);

void			eftext(t_bunny_zpixelarray		*pix,
			       t_bunny_pixelarray		*font,
			       t_zposition			*pos,
			       const char			*txt,
			       t_bunny_color			*font_color);

typedef struct		s_blit
{
  t_bunny_position	shift;
  t_bunny_position	src_pos;
  t_bunny_position	target_pos;
  t_bunny_position	final_pos;
  t_bunny_position	clip;
  int			src_limit;
  int			target_limit;
  t_bunny_position	size_dest;
  bool			is_x_reverse;
  bool			is_y_reverse;
}			t_blit;

#endif //		__LAB_H__
