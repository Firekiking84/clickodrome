#include	"gui.h"

static void	efcheck_click_pos(t_button				*button,
				  t_bunny_mouse_button_event const	*event)
{
   if (event->x > button->pos.x &&
       event->x < button->pos_end.x &&
       event->y > button->pos.y &&
       event->y < button->pos_end.y)
     button->in_button = true;
}

static void	efcheck_move_pos(t_button				*button,
				 t_bunny_mouse_move_event const		*event)
{
   if (event->x > button->pos.x &&
       event->x < button->pos_end.x &&
       event->y > button->pos.y &&
       event->y < button->pos_end.y)
     button->is_hover = true;
   else
     button->is_hover = false;
}

void		efevent_button(t_button					*button,
			       t_bunny_event const			*event)
{
  size_t	count;
  void		(*func_ptr)(t_gui	*,
			    void	*);

  count = 0;
  if (event->type == BET_MOUSE_MOVED)
    efcheck_move_pos(button, &event->mouse_moved);
  else if (button->focus == true && event->key.sym == BKS_RETURN)
    {
      while (count < button->functions->data_count)
	{
	  func_ptr = efvector_ptr_get(button->functions, count);
	  func_ptr(button->gui, button->lib->data);
	  count++;
	}
    }
  else if (event->type == BET_MOUSE_BUTTON_PRESSED)
    {
      if(event->mouse_button.button == BMB_LEFT)
	efcheck_click_pos(button, &event->mouse_button);
    }
  else if (event->type == BET_MOUSE_BUTTON_RELEASED)
    {
      if (button->in_button == true)
	efcheck_click_pos(button, &event->mouse_button);
      if (button->in_button == true)
	{
	while (count < button->functions->data_count)
	  {
	    func_ptr = efvector_ptr_get(button->functions, count);
	    func_ptr(button->gui, button->lib->data);
	    count++;
	  }
	}
      button->in_button = false;
    }
}
