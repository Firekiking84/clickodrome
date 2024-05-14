#include		"picture.h"

static void		format_picture(t_bunny_pixelarray	*px,
				       t_bunny_size		pic_size)
{
  px->clipable.clip_x_position = 0;
  px->clipable.clip_y_position = 0;
  px->clipable.scale.x = (double)pic_size.x / px->clipable.clip_width;
  if ((px->clipable.clip_height * px->clipable.scale.x) > pic_size.y)
    px->clipable.scale.x = (double)pic_size.y / px->clipable.clip_height;
  px->clipable.scale.y = px->clipable.scale.x;
}

t_picture               *efnew_picture(t_picture_settings	*settings)
{
  t_picture		*pict;

  if ((pict =  bunny_malloc(sizeof(t_picture))) == NULL)
    {
      perror(" bunny_malloc new_picture");
      return (NULL);
    }
  if ((pict->name =  bunny_malloc(strlen(settings->name))) == NULL)
    {
      bunny_free(pict);
      perror(" bunny_malloc new_picture_name");
      return (NULL);
    }
  if ((pict->img = bunny_load_pixelarray(settings->filename)) == NULL)
    {
      bunny_free(pict->name);
      bunny_free(pict);
      perror(" bunny_malloc new_picture_img");
      return (NULL);
    }
  strcpy(pict->name, settings->name);
  pict->size = settings->size;
  pict->pos = settings->pos;
  format_picture(pict->img, pict->size);
  return (pict);
}
