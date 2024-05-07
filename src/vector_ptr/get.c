#include		"vector_ptr.h"

void			*efvector_ptr_get(t_vector_ptr const	*vec,
					  size_t		index)
{
  if (index >= vec->data_count)
    return(NULL);
  return((void *)vec->data_array[index]);
}
