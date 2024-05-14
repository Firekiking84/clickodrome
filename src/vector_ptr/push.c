#include		"vector_ptr.h"

int			efvector_ptr_push(t_vector_ptr	*vec,
					  const void	*ptr)
{
  if (vec->data_count >= vec->array_capacity)
    {
      if (efvector_ptr_resize(vec, vec->array_capacity + 10) == -1)
	return(-1);
    }
  vec->data_count += 1;
  vec->data_array[vec->data_count - 1] = (size_t)ptr;
  return(0);
}
