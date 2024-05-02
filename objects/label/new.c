#include		"label.h"
#include		"draw.h"

t_label			*efnew_label(t_label_settings	*settings)
{
  t_label		*label;

  if ((label =  bunny_malloc(sizeof(t_label))) == NULL)
    {
      perror(" bunny_malloc new_label");
      return (NULL);
    }
  label->pos = *zpos;
  label->size = size;
  label->name = settings->name;
  label->text = settings->text;
  label->font_color = font_color;
  label->bg = bg;
  return (label);
}
