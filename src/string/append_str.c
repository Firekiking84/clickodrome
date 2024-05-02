#include		"efstring.h"

#include		<stdlib.h>
#include		<string.h>

int			string_append_str(t_string		*string,
					  const char		*str)
{
  int			len_str;

  len_str = strlen(str);
  if ((string->str_len + len_str) > string->size_alloc)
    {
      string->size_alloc += sizeof(char) * (string->str_len + len_str + 1);
      string->str = realloc(string->str, string->size_alloc);
      if (!string->str)
	return(-1);
    }
  strcat(string->str, str);
  string->str_len += len_str;
  return(0);
}
