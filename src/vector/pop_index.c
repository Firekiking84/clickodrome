#include		"vector.h"

// Ecrase la valeur a la position index par la valeur a la last_index
static void		remp(t_vector				*vec,
			     size_t				index,
			     size_t				last_index)
{
  efmemcpy((&((char*)vec->data_array)[index * vec->sizeof_data]),
	   (&((char*)vec->data_array)[last_index * vec->sizeof_data]), vec->sizeof_data);
}

void			efvector_pop(t_vector			*vec,
				     size_t			index)
{
  if (index < vec->data_count - 1)
    remp(vec, index, vec->data_count - 1);
  else if (index >= vec->data_count)
    {
      perror("index segmentation fault");
      return ;
    }
  if (vec->data_count < (vec->array_capacity / 2))
    {
      vec->data_array = realloc(vec->data_array,			\
				(vec->array_capacity *			\
				 vec->sizeof_data) / 2);
      if (vec->data_array == NULL)
	return;
    }
  vec->data_count --;
}
