#ifndef			__DRAW_H__

#define			__DRAW_H__

#include		<lapin.h>

typedef struct          s_bunny_pixelarray
{
  t_bunny_pixelarray    *px;
  double                *z;
}		        t_bunny_pixelarray;

typedef struct		s_zposition
{
  int			x;
  int			y;
  double		z;
}			t_bunny_position;

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

typedef struct		s_letter_settings
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  t_bunny_size		font_size;
  t_bunny_position	pos;
  t_bunny_color         *col;
  char			c;
}t_letter_settings;
typedef struct		s_text_settings
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  t_bunny_size		font_size;
  t_bunny_position	pos;
  t_bunny_position	pos_end;
  char			*txt;
  t_bunny_color		*font_color;
}			t_text_settings;

void                    efclear_zbuffer(t_bunny_pixelarray     *zpx);
void			efclear_pixelarray(t_bunny_pixelarray	*zpx,
					   unsigned int		col);
void			set_pixel(t_bunny_pixelarray		*px,
				  t_bunny_position	        pos,
				  t_bunny_color			*col);
void			set_pixel(t_bunny_pixelarray		*px,
				   t_bunny_position			*pos,
				   t_bunny_color		*col);
void			draw_rectangle(t_bunny_pixelarray	*px,
				       t_bunny_position		*posStart,
				       t_bunny_position		*posEnd,
				       t_bunny_color		*col);
void			blit(t_bunny_pixelarray		*target,
			     const t_bunny_pixelarray		*src,
			     const t_bunny_position			*pos,
			     t_bunny_color			*forcedCol);
double			get_ratio(int				a,
				  int				b,
				  int				x);
int			get_value(int				a,
				  int				b,
				  double			ratio);
int			get_npos(int				width,
				 t_bunny_position		pos);
void			efletter(t_letter_settings		*set);
void			eftext(t_text_settings			*set);


#endif //		__DRAW_H__
