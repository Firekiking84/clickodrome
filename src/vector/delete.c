#include                "vector.h"

size_t                  efvector_delete(t_vector            *vec)
{
    size_t              size;

    size = vec->data_count;
    if (vec == NULL)
        return (0);
    if (vec->is_view == false)
        free(vec->data_array);
    free(vec);
    vec = NULL;
    return (size);
}
