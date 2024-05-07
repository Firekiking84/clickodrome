#include		"div.h"

#include		<stdio.h>

static bool		short_return(const char				*err_msg)
{
  dprintf(2, err_msg);
  return(false);
}

bool			efcheck_pos_new_component(t_div			*div,
						  t_zposition		*pos,
						  t_bunny_size		*size)
{
  int			end_pos;

  if (size->x <= 0 || size->y <= 0)
    return(short_return("Wrong size values !"));
  if (pos->x < div->pos.x)
    pos->x = div->pos.x;
  if (pos->y < div->pos.y)
    pos->y = div->pos.y;
  if (pos->x >= div->end_pos.x || pos->y >= div->end_pos.y )
    return(short_return("Cannot add component out of concerned area !"));
  end_pos = pos->x + size->x;
  if (end_pos >= div->end_pos.x)
    {
      size->x -= (end_pos - div->end_pos.x) + 1;
      if (size->x <= 0)
	return(short_return("Cannot add component out of concerned area !"));
    }
  end_pos = pos->y + size->y;
  if (end_pos >= div->end_pos.y)
    {
      size->y -= (end_pos - div->end_pos.y) + 1;
      if (size->y <= 0)
	return(short_return("Cannot add component out of concerned area !"));
    }
  return(true);
}
