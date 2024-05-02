#include		"vector_ptr.h"

#include		<lapin.h>

void			efvector_ptr_delete(t_vector_ptr	*vec)
{
  if (vec->data_array)
    bunny_free(vec->data_array);
  bunny_free(vec);
}
