#include		"text_box.h"

void			efdelete_text_box(t_text_box	*text_box)
{
  free(text_box->name);
  free(text_box->text);
  if (text_box->bg)
    free(text_box->bg);
  efvector_delete(text_box->functions);
  free(text_box);
}
