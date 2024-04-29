#ifndef			__BUTTON_H__

#define			__BUTTON_H__

typedef struct	        s_button
{
  t_zposition	        *pos;
  t_bunny_size		size;
  const char		*name;
  const char		*text;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
  t_vector		*functions;
}			t_button;

t_button		*efnew_button(t_zposition		*pos,
				      t_bunny_size		size,
				      const char		*name,
				      const char		*text,
				      t_bunny_color		*font_color,
				      t_bunny_color		*bg,
				      t_bunny_color             *hover_color,
				      t_vector			*function);
void			efdelete_button(t_button		*button);
void			efdisplay_button(t_button		*button,
					 t_bunny_pixelarray	*px);

#endif	//		__BUTTON_H__
