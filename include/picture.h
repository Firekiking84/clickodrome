
#ifndef			__PICTURE_H__

#define			__PICTURE_H__

#include		"draw.h"

typedef struct	        s_picture
{
  t_zposition		pos;
  t_bunny_size		size;
  char			*name;
  t_bunny_pixelarray	*img;
}			t_picture;
typedef struct		s_picture_settings
{
  t_zposition		pos;
  t_bunny_size		size;
  char			*name;
  char			*filename;
}			t_picture_settings;

t_picture		*efnew_picture(t_picture_settings	*set);
void			efdelete_picture(t_picture		*picture);
void			efdisplay_picture(t_picture		*picture,
					  t_bunny_zpixelarray	*px);
void			efedit_picture(t_picture		*picture,
				      t_picture_settings	*edit);


#endif	//		__PICTURE_H__
