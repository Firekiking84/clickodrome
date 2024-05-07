#include		"picture.h"

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
  return (pict);
}
