/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 14/05/2024 16:28:04 ******************************************************
** kenan.guidat <kenan.guidat@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"label.h"

static void		edit2(t_label                    *label,
			      t_label_settings const     *edit)
{
  if (edit->font_size.x > 0)
    label->font_size = edit->font_size;
  if (edit->font_color)
    {
      if (label->font_color)
	bunny_free(label->font_color);
      label->font_color = edit->font_color;
    }
  if (edit->bg)
    {
      if (label->bg)
	bunny_free(label->bg);
      label->bg = edit->bg;
    }
}

void			efedit_label(t_label			*label,
				     t_label_settings const	*edit)
{
  t_bunny_pixelarray	*new_font;

  if (edit->pos.x >= 0)
    label->pos = edit->pos;
  if (edit->size.x > 0)
    label->size = edit->size;
  if (edit->text)
    {
      if (label->text)
	bunny_free(label->text);
      label->text = edit->text;
    }
    if (edit->font)
    {
      new_font = bunny_load_pixelarray(edit->font);
      if (new_font)
	{
	  bunny_delete_clipable(label->font);
	  label->font = new_font;
	}
    }
    edit2(label, edit);
}
