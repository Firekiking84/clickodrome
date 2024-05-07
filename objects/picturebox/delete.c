#include		"picture.h"

void                    efdelete_picture(t_picture             *picture)
{
  if (picture == NULL)
    return;
  bunny_free(picture->name);
  bunny_free(picture->img);
  bunny_free(picture);
}
