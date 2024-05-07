#include		"vector_ptr.h"

t_vector_ptr		*efvector_ptr_new_vector(t_vector_ptr const	*other)
{
  t_vector_ptr		*new;
  size_t		i;

  new = efvector_ptr_new(other->data_count);
  i = 0;
  while (i < other->data_count)
    {
      if (efvector_ptr_push(new, efvector_ptr_get(other, i)) == -1)
	{
	  efvector_ptr_delete(new);
	  return(NULL);
	}
      i += 1;
    }
  return(new);
}
