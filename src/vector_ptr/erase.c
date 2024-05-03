#include		"vector_ptr.h"

void			efvector_ptr_erase(t_vector_ptr	*vec,
					   size_t	index)
{
  if (index >= vec->data_count)
    return;
  if (vec->data_count > 1)
    {
      vec->data_array[index] = vec->data_array[vec->data_count - 1];
      vec->data_array[vec->data_count - 1] = 0;
    }
  else
    vec->data_array[index] = 0;
  vec->data_count -= 1;
}
