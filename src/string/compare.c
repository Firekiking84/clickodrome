#include		"efstring.h"

#include		<string.h>

int			string_compare(const t_string		*string,
				       const t_string		*other)
{
  return(strcmp(string->str, other->str));
}
