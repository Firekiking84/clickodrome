#ifndef			__TEXT_BOX_H__

#define			__TEXT_BOX_H__

typedef struct	        s_text_box
{
  t_bunny_position	*pos;
  t_bunny_size		size;
  const char		*name;
  const char		*text;
  t_bunny_color		*font_color;
  t_bunny_color		*bg;
  t_vector		*functions;
}			t_text_box;

t_text_box		*efnew_text_box(t_bunny_position	*pos,
					t_bunny_size		size,
					const char		*name,
					const char		*text,
					t_bunny_color		*font_color,
					t_bunny_color		*bg,
					t_vector		*functions);
void			efdelete_text_box(t_text_box		*text_box);
void			efdisplay_txt_boxe(t_text_box		*text_box,
					   t_bunny_pixelarray	*px);


#endif	//		__TEXT_BOX_H__
