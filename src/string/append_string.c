#include		"efstring.h"

#include		<stdlib.h>
#include		<string.h>

int			string_append_string(t_string		*string,
					     const t_string	*other)
{
  if ((string->str_len + other->str_len) > string->size_alloc)
    {
      string->size_alloc += sizeof(char) * (string->str_len + other->str_len + 1);
      string->str = realloc(string->str, string->size_alloc);
      if (!string->str)
	return(-1);
    }
  strcat(string->str, other->str);
  string->str_len += other->str_len;
  return(0);
}
