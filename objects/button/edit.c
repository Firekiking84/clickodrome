#include		"button.h"

void			efedit_button(t_button			*button,
				      t_button_settings const	*edit)
{
  t_bunny_pixelarray	*new_font;

  if (edit->pos.x >= 0)
    button->pos = edit->pos;
  if (edit->size.x > 0)
    button->size = edit->size;
  if (edit->text)
    {
      bunny_free(button->text);
      button->text = edit->text;
    }
  if (edit->font)
    {
      new_font = bunny_load_pixelarray(edit->font);
      if (new_font)
	{
	  bunny_delete_clipable(button->font);
	  button->font = new_font;
	}
    }
  if (edit->font_size.x > 0)
    button->font_size = edit->font_size;
  if (edit->font_color)
    {
      if (!button->font_color)
	bunny_free(button->font_color);
      button->font_color = edit->font_color;
    }
  if (edit->hover_color)
    {
      if (button->hover_color)
	bunny_free(button->hover_color);
      button->hover_color = edit->hover_color;
    }
  if (edit->bg)
    {
      if (button->bg)
	bunny_free(button->bg);
      button->bg = edit->bg;
    }
  if (edit->functions)
    {
      efvector_ptr_delete(button->functions);
      efvector_ptr_new((size_t)edit->functions);
    }
}
