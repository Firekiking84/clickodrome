#include		"label.h"
#include		"draw.h"

t_label			*efnew_label(t_bunny_zpixelarray	*zpx,
				     t_bunny_pixelarray		*font,
				     t_zposition		zpos,
				     t_bunny_size		size,
				     const char			*name,
				     const char			*text,
				     t_bunny_color		*font_color,
				     t_bunny_color		*bg)
{
  t_label		*label;

  label = malloc(sizeof(t_label));
  label->pos = zpos;
  label->size = size;
  label->name = name;
  label->text = text;
  label->font_color = font_color;
  label->bg = bg;
}