#include                "vector.h"

size_t                  efvector_clear(t_vector         *vec)
{
    size_t              size;

    size = vec->data_count;
    vec->data_count = 0;
    return (size);
}
