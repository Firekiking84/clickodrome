#include		"vector_ptr.h"

int			efvector_ptr_push(t_vector_ptr	*vec,
					  const void	*ptr)
{
  vec->data_count += 1;
  if (vec->data_count >= vec->array_capacity)
    {
      if (vector_resize(vec, vec->array_capacity + 10) == -1)
	return(-1);
    }
  vec->data_array[vec->data_count - 1] = (size_t)ptr;
}
