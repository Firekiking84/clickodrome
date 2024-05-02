#include		"vector_ptr.h"

t_vector_ptr		*efvector_ptr_new(size_t		initial_capacity)
{
  t_vector_ptr		*new_vec;

  new_vec = bunny_malloc(sizeof(*new_vec));
  if (!new_vec)
    return(NULL);
  new_vec->array_capacity = initial_capacity;
  new_vec->data_count = 0;
  if (new_vec->array_capacity > 0)
    {
      new_vec->data_array = bunny_malloc(sizeof(void *) * new_vec->array_capacity);
      if (!new_vec->data_array)
	{
	  free(new_vec);
	  return(NULL);
	}
    }
  else
    new_vec->data_array = NULL;
  return(new_vec);
}
