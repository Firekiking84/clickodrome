#include		"efstring.h"

int			string_pop_back(t_string	*string)
{
  if (string->str_len > 0)
    {
      string->str_len -= 1;
      string->str[string->str_len] = '\0';
      return(1);
    }
    return(0);
}
