#include		"text_box.h"

void			cut_selection(t_text_box		*box)
{
  copy_selection(box);
  erase_selection(box);
}
