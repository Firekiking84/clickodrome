#include		"efstring.h"

#include		<stdlib.h>

int			string_shrink_to_fit(t_string		*string)
{
  if (string->str)
    {
      if (string->size_alloc != (string->str_len + 1))
	{
	  if (efstring_resize(string, string->str_len + 1) == -1)
	    return(-1);
	}
      return(1);
    }
  return(0);
}
