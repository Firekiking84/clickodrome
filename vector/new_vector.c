#include		"vector.h"

t_vector		*efvector_new_vector(t_vector const	*other)
{
  t_vector		*new_vector;

  new_vector = _efvector_new(other->sizeof_data, other->data_count);
  efmemcpy(new_vector->data_array, other->data_array, (other->sizeof_data * other->data_count));
  new_vector->data_count = other->data_count;
  return(new_vector);
}
