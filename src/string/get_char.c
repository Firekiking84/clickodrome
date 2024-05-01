#include		"efstring.h"

char			string_get_char(t_string	*string,
					int		index)
{
  if (index >= 0 && index < string->str_len)
    return(string->str[index]);
  return('\0');
}
