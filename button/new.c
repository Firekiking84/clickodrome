#include "button.h"

t_button		*efnew_button(t_zposition		pos,
				      t_bunny_size		size,
				      const char		*name,
				      const char		*text,
				      bool			focus,
				      bool			in_button,
				      t_bunny_color		*font_color,
				      t_bunny_color		*bg,
				      t_vector			*function)

{
  t_button button;

  if ((buttons =malloc (sizeof(*buttons))) == NULL)
      return(NULL);
  button.pos = pos;
  button.size= size;
  button.text = text;
  button.focus = focus;
  button.in_button = in_button;
  button.name = name;
  button.font_color = font_color;
  button.bg = bg;
  button.functions = function;
}
