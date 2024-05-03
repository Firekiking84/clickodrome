#include		"vector_ptr.h"

#include		<lapin.h>

int			efvector_ptr_resize(t_vector_ptr	*vec,
					    size_t		new_size)
{
  size_t		*new_array;
  size_t		i;

  vec->array_capacity = new_size;
  if (new_size < vec->data_count)
    vec->data_count = new_size;
  new_array = bunny_malloc(sizeof(size_t) * vec->array_capacity);
  if (!new_array)
    return(-1);
  i = 0;
  while (i < vec->data_count)
    {
      new_array[i] = vec->data_array[i];
      i += 1;
    }
  if (vec->data_array)
    bunny_free(vec->data_array);
  vec->data_array = new_array;
  return(0);
}
