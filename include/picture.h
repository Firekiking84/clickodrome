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

t_picture		*efnew_picture(t_zposition		*pos,
				       t_bunny_size		size,
				       const char		*name,
				       const char		*filename);
void			efdelete_picture(t_picture		*picture);
void			efdisplay_picture(t_picture		*picture,
					  t_bunny_zpixelarray	*px);


#endif	//		__PICTURE_H__
