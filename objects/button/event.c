#include	"gui.h"

static void	efcheck_pos(t_button				*button,
			  t_bunny_mouse_button_event const	*event)
{
   if (event->x < button->pos.x &&
       event->x > button->pos.x + button->size.x &&
       event->y > button->pos.y &&
       event->y < button->pos.y + button->size.y)
     button->in_button = true;
}

void		efevent_button(t_button			*button,
			       t_bunny_event const		*event)
{
  size_t	count;
  void		(*func_ptr)(t_gui	*,
			    void	*);

  count = 0;
  if (button->focus == true && event->key.sym == BKS_RETURN )
    {
      while (count < button->functions->data_count)
	{
	  func_ptr = efvector_ptr_get(button->functions, count);
	  func_ptr(button->gui, button->lib->data);
	  count++;
	}
    }
  if ( event->type == BET_MOUSE_BUTTON_PRESSED)
    if( event->mouse_button.button == BMB_LEFT)
      efcheck_pos(button, &event->mouse_button);
  if ( event->type == BET_MOUSE_BUTTON_RELEASED)
    {
      if (button->in_button == true)
	efcheck_pos(button, &event->mouse_button);
      if (button->in_button == true)
	while (count < button->functions->data_count)
	  {
	    func_ptr = efvector_ptr_get(button->functions, count);
	    func_ptr(button->gui, button->lib->data);
	    count++;
	  }
    }
}
