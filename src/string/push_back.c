#include		"efstring.h"
#include		<stdlib.h>

int			string_push_back(t_string	*string,
					 char		c)
{
  if (!string->str)
    {
      string->size_alloc = 2;
      string->str = bunny_malloc(sizeof(char) * 2);
      if (!string->str)
	return(-1);
      string->str_len = 0;
    }
  string->str_len += 1;
  if (string->str_len == string->size_alloc)
    {
      string->size_alloc += sizeof(char) * 10;
      string->str = realloc(string->str, string->size_alloc);
      if (!string->str)
	return(-1);
    }
  string->str[string->str_len - 1] = c;
  string->str[string->str_len] = '\0';
  return(0);
}
