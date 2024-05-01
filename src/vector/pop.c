#include                "vector.h"

void                    efvector_pop_back(t_vector          *vec)
{
    if (vec->data_count < (vec->array_capacity / 2))
        {
            vec->data_array = realloc(vec->data_array,                  \
                                      (vec->array_capacity *            \
                                       vec->sizeof_data) / 2);
            if (vec->data_array == NULL)
                return;
        }
    vec->data_count --;
}
