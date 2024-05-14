#include		"picture.h"

void                    efdisplay_picture(t_picture             *picture,
					  t_bunny_pixelarray	*px)
{
  blit(px, picture->img, &picture->pos, NULL);
}
