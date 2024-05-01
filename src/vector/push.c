#include                "vector.h"

void                    *efvector_push(t_vector             *vec,
                                       const void           *data)
{
    if (vec->array_capacity == vec->data_count)
        {
            vec->data_array = realloc(vec->data_array, (vec->array_capacity * vec->sizeof_data) * 2);
            if (vec->data_array == NULL)
                return (NULL);
            vec->array_capacity = vec->array_capacity * 2;
        }
    efmemcpy((&((char*)vec->data_array)[vec->data_count * vec->sizeof_data]) \
             , data, vec->sizeof_data);
    vec->data_count ++;
    return ((&((char*)vec->data_array)[(vec->data_count - 1) * vec->sizeof_data]));
}
