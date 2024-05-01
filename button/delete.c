#include "button.h"
size_t			efdelete_button(t_button		*button)
{
  size_t size;

  size = efvector_delete(button->functions);
  return(size);
}
