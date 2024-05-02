#include		"vector_ptr.h"

void			efvector_ptr_delete(t_vector_ptr	*vec)
{
  if (vec->data_array)
    free(vec->data_array);
  free(vec);
}
