#include		"efstring.h"

#include		<stdlib.h>

t_string		*string_new()
{
  t_string		*new_string;

  new_string = malloc(sizeof(*new_string));
  if (!new_string)
    return(NULL);
  new_string->str = NULL;
  new_string->size_alloc = 0;
  new_string->str_len = 0;
  return(new_string);
}
