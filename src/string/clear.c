#include		"efstring.h"

int			string_clear(t_string		*string)
{
  int			len_str;

  len_str = string->str_len;
  if (string->str && string->str_len > 0)
    {
      string->str[0] = '\0';
      string->str_len = 0;
      return(len_str);
    }
  return(0);
}
