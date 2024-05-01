#include                "vector.h"

void                    *efmemcpy(void           *trg,
                                  const void     *src,
                                  size_t         size)
{
    char                *trgt;
    char                *sr;
    size_t              i;

    i = 0;
    trgt = (char*)trg;
    sr = (char*)src;
    while (i < size)
        {
            trgt[i] = sr[i];
            i ++;
        }
    return (trg);
}
