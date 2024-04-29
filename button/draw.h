#ifndef		__DRAW_H__

#define		__DRAW_H__

#include	<lapin.h>

typedef struct	s_zposition
{
  int		x;
  int		y;
  double	z;
}		t_zposition;

void		set_pixel(t_bunny_pixelarray		*px,
			  t_zposition		        pos,
			  t_bunny_color			col);
void		set_zpixel(t_bunny_zpixelarray		*px,
			  t_zposition			pos,
			  t_bunny_color			col);
void		draw_rectangle(t_bunny_pixelarray	*px,
			       t_zposition		posStart,
			       t_zposition		posEnd,
			       t_bunny_color		*col);
void		blit(t_bunny_pixelarray			*target,
		     const t_bunny_pixelarray		*src,
		     const t_bunny_position		*pos,
		     t_bunny_color			*forcedCol);
double		get_ratio(int				a,
			  int				b,
			  int				x);
int		get_value(int				a,
			  int				b,
			  double			ratio);
int		get_npos(int				width,
			 t_bunny_position		pos);

void            efletter(t_bunny_zpixelarray		*pix,
			 t_bunny_pixelarray		*font,
			 t_zposition			pos,
			 char				c);

void            eftext(t_bunny_zpixelarray		*pix,
		       t_bunny_pixelarray		*font,
		       t_zposition			pos,
		       const char			*str,
		       t_bunny_color			*col);

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


#endif //	__DRAW_H__
