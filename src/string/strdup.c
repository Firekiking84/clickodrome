#include		<string.h>
#include		<lapin.h>

char			*efstrdup(const char	*str)
{
  int			len;
  char			*new_str;

  len = strlen(str);
  new_str = bunny_malloc(sizeof(char) * (len + 1));
  if (!new_str)
    return(NULL);
  strcpy(new_str, str);
  new_str[len] = '\0';
  return(new_str);
}
