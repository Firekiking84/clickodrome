#include		"efstring.h"

#include		<stdlib.h>

void			string_delete(t_string	*string)
{
  if (string->str)
    free(string->str);
  free(string);
}
