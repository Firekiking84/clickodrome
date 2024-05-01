#include                "vector.h"

t_vector                *efvector_view(t_vector         *vec,
                                       size_t           start,
                                       size_t           len)
{
    t_vector            *view_vect;

    view_vect = bunny_malloc(sizeof(t_vector));
    if (view_vect == NULL)
      return (NULL);
    view_vect->sizeof_data = vec->sizeof_data;
    view_vect->array_capacity = (start + len) < vec->array_capacity ?   \
        len : (vec->array_capacity - start);
    view_vect->is_view = true;
    view_vect->data_array = &((char *)vec->data_array)  \
        [start * vec->sizeof_data];
    view_vect->data_count = (start + len) < vec->array_capacity ?       \
        len : (vec->array_capacity - start);
    return (view_vect);
}
