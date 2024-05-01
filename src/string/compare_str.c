#include		"efstring.h"

#include		<string.h>

int			string_compare_str(const t_string		*string,
					   const char			*str)
{
  return(strcmp(string->str, str));
}
