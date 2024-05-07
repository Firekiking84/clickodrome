#include		"picture.h"

void                    efdisplay_picture(t_picture             *picture,
					  t_bunny_pixelarray	*px)
{
  t_bunny_area		save;

  save.x = picture->img->clipable.clip_x_position;
  save.y = picture->img->clipable.clip_y_position;
  save.w = picture->img->clipable.buffer.width;
  save.h = picture->img->clipable.buffer.height;
  if (picture->pos.x < picture->img->clipable.buffer.width)
    picture->img->clipable.clip_x_position = picture->pos.x;
  if (picture->pos.y < picture->img->clipable.buffer.height)
    picture->img->clipable.clip_y_position = picture->pos.y;
  if (picture->pos.x + picture->size.x < save.x + picture->img->clipable.buffer.width)
    picture->img->clipable.buffer.width = picture->size.x;
  else
    picture->img->clipable.buffer.width -= picture->pos.x;
  if (picture->pos.y + picture->size.y < save.y + picture->img->clipable.buffer.height)
    picture->img->clipable.buffer.height = picture->size.y;
  else
    picture->img->clipable.buffer.height -= picture->pos.y;
  blit(px, picture->img, &picture->pos, NULL);
  picture->img->clipable.clip_x_position = save.x;
  picture->img->clipable.clip_y_position = save.y;
  picture->img->clipable.buffer.width = save.w;
  picture->img->clipable.buffer.height = save.h;
}
