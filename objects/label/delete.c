#include		"label.h"

void                    efdelete_label(t_label                  *label)
{
  if (label == NULL)
    return;
  free(label->name);
  free(label->text);
  free(label);
}
