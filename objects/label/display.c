/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 14/05/2024 16:30:38 ******************************************************
** kenan.guidat <kenan.guidat@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"label.h"

void                    efdisplay_label(t_label                 *label,
					t_bunny_pixelarray     *px)
{
  t_bunny_position	pos_end;
  t_text_settings	set;

  pos_end = label->pos_end;
  if (label->bg != NULL)
    {
      pos_end.y = label->pos.y + label->size.y;
      draw_rectangle(px, &label->pos, &pos_end, label->bg);
    }
  set.pix = px;
  set.font = label->font;
  set.font_size = label->font_size;
  set.pos = label->pos;
  set.pos_end = label->pos_end;
  set.txt = label->text;
  set.font_color = label->font_color;
  eftext(&set);
}
