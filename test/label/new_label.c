#include		"label.h"

t_label			*efnew_label(t_zposition		*zpos,
				     t_bunny_size		size,
				     const char			*name,
				     const char			*text,
				     t_bunny_color		*font_color,
				     t_bunny_color		*bg)
{
  t_label		*label;

  if ((label = bunny_malloc(sizeof(t_label))) == NULL)
    {
      perror("malloc new_label");
      return (NULL);
    }
  label->pos = *zpos;
  label->size = size;
  if ((label->name = bunny_malloc(strlen(name))) == NULL)
    {
      perror("malloc new_label_name");
      return (NULL);
    }
  if ((label->text = bunny_malloc(strlen(text))) == NULL)
    {
      perror("malloc new_label_text");
      return (NULL);
    }
  strcpy(label->name, name);
  strcpy(label->text, text);
  label->font_color = font_color;
  label->bg = bg;
  return (label);
}
