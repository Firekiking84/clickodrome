#include	"div.h"

void		efevent_div(t_div			*div,
			    const t_bunny_event		*event)
{
  size_t	count;

  if ( event->type == BET_MOUSE_MOVED)
    {
      if (event->mouse_moved.x > div->pos.x &&
	  event->mouse_moved.x < div->pos.x + div->size.x &&
	  event->mouse_moved.y < div->pos.y &&
	  event->mouse_moved.y > div->pos.y + div->size.y)
	div->in_div = false ;
      else
	div->in_div = true ;
    }
  else
    {
      if (div->in_div == true)
	{
	  count = 0;
	  while (count < div->buttons->data_count)
	  {
	    efevent_button(efvector_ptr_get(div->buttons, count), event);
	    count++;
	  }
	  count = 0;
	  while (count < div->text_boxes->data_count)
	    {
	      efevent_text_box(efvector_ptr_get(div->text_boxes, count), event);
	      count++;
	    }
	}
    }
}
