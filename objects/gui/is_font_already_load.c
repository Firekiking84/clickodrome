#include		"gui.h"
#include		"efstring.h"

t_bunny_pixelarray	*is_font_already_load(const char		*font_name,
					      t_gui			*gui)
{
  size_t		i;
  t_font		*font;

  i = 0;
  while (i < gui->fonts->data_count)
    {
      font = efvector_ptr_get(gui->fonts, i);
      if (strcmp(font_name, font->name) == 0)
	return(font->px);
      i += 1;
    }
  font = bunny_malloc(sizeof(t_font));
  font->name = efstrdup(font_name);
  font->px = bunny_load_pixelarray(font->name);
  efvector_ptr_push(gui->fonts, font);
  return(font->px);
}
