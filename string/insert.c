#include		"efstring.h"

#include		<stdlib.h>

int			string_insert(t_string			*string,
				      int			index,
				      char			c)
{
  int			i;

  if (index < 0 || index > string->str_len)
    return(-1);
  if (!string->str || index == string->str_len)
    return(string_push_back(string, c));
  string->str_len += 1;
  if (string->str_len == string->size_alloc)
    {
      string->size_alloc += sizeof(char) * 10;
      string->str = realloc(string->str, string->size_alloc);
      if (!string->str)
	return(-1);
    }
  i = string->str_len;
  while (i > index)
    {
      string->str[i] = string->str[i - 1];
      i -= 1;
    }
  string->str[i] = c;
  return(0);
}
