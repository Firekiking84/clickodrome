#include		"text_box.h"

void			manage_control_key(t_text_box		*text_box,
					   const t_bunny_event	*event)
{
  if (text_box->selection_active)
    {
      if (event->key.sym == BKS_C)
	copy_selection(text_box);
      else if (event->key.sym == BKS_X)
	cut_selection(text_box);
      else if (event->key.sym == BKS_V)
	{
	  erase_selection(text_box);
	  paste(text_box);
	}
    }
  else if (event->key.sym == BKS_V)
    paste(text_box);
  text_box->selection_active = false;
}
