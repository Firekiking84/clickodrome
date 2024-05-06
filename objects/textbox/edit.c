/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 15:59:29 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"text_box..h"

void			efedit_textbox(t_text_box		*picture,
				       t_textbox_settings const	*edit)
{
  t_bunny_pixelarray	*new_font;

  if (edit->pos.x >= 0)
    textbox->pos = edit->pos;
  if (edit->size.x > 0)
    textbox->size = edit->size;
  if (edit->text)
    {
      bunny_free(textbox->text);
      textbox->text = edit->text;
    }
  if (edit->font)
    {
      new_font = bunny_load_pixelarray(edit->font);
      if (new_font)
	{
	  bunny_delete_clipable(textbox->font);
	  textbox->font = new_font;
	}
    }
  if (edit->font_size.x > 0)
    textbox->font_size = edit->font_size;
  if (edit->font_color)
    {
      if (!textbox->font_color)
	bunny_free(textbox->font_color);
      textbox->font_color = edit->font_color;
    }
  if (edit->bg)
    {
      if (textbox->bg)
	bunny_free(textbox->bg);
      textbox->bg = edit->bg;
    }
  if (edit->functions)
    {
      efvector_ptr_delete(textbox->functions);
      efvector_ptr_new(edit->functions);
    }
}
