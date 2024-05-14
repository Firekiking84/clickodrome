#include		"clickodrome.h"

static void		switch_focus(t_gui			*gui,
				     int			new_focus)
{
  if (new_focus > gui->components->data_count || new_focus < 0)
    new_focus = 0;
  if (gui->focus_element->type == BUTTON)
    gui->focus_element->button->focus = false;
  else
    gui->focus_element->textbox->has_focus = false;
  gui->focus_element = efvector_ptr_get(gui->components, new_focus);
  if (gui->focus_element->type == BUTTON)
    gui->focus_element->button->focus = true;
  else
    gui->focus_element->textbox->has_focus = true;
  gui->index_focus = new_focus;
}

void			efevent_gui(t_bunny_event const		*event,
				    void			*data)
{
  size_t		count ;
  t_program		*dataptr;
  int			new_focus;

  dataptr = (t_program *)data;
  if (event->type == BET_KEY_PRESSED && event->key.sym == BKS_TAB)
    switch_focus(dataptr->gui, dataptr->gui->index_focus + 1);
  else
    {
      count = 0;
      while (count < dataptr->gui->divs->data_count)
	{
	  new_focus = efevent_div(efvector_ptr_get(dataptr->gui->divs, count), event);
	  if (new_focus != -2)
	    switch_focus(dataptr->gui, new_focus);
	  count++;
	}
    }
}
