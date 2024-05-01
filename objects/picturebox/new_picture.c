#include		"picture.h"

t_picture               *efnew_picture(t_zposition		pos,
				       t_bunny_size             size,
				       const char               *name,
				       const char               *filename)
{
  t_picture		*pict;

  if ((pict =  bunny_malloc(sizeof(t_picture))) == NULL)
    {
      perror(" bunny_malloc new_picture");
      return (NULL);
    }
  if ((pict->name =  bunny_malloc(strlen(name))) == NULL)
    {
      free(pict);
      perror(" bunny_malloc new_picture_name");
      return (NULL);
    }
  if ((pict->img = bunny_load_pixelarray(filename)) == NULL)
    {
      free(pict->name);
      free(pict);
      perror(" bunny_malloc new_picture_img");
      return (NULL);
    }
  strcpy(pict->name, name);
  pict->size = size;
  pict->pos = pos;
  return (pict);
}
