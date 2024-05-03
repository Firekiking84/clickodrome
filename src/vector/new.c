#include                    "vector.h"

t_vector                    *_efvector_new(size_t              elem_size,
                                           size_t              initial_capacity)
{
    t_vector                *new_vect;

    new_vect = bunny_malloc(sizeof(t_vector));
    if (new_vect == NULL)
        return (NULL);
    new_vect->data_array = bunny_malloc(initial_capacity * elem_size);
    if (new_vect->data_array == NULL)
        return (NULL);
    new_vect->sizeof_data = elem_size;
    new_vect->array_capacity = initial_capacity;
    new_vect->data_count = 0;
    new_vect->is_view = false;
    return (new_vect);
}
