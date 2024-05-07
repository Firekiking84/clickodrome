#include		"label.h"

void                    efdisplay_label(t_label                 *label,
					t_bunny_zpixelarray     *zpx)
{
  t_zposition		pos_end;
  t_text_settings	set;

  pos_end = label->pos_end;
  if (label->bg != NULL)
    {
      pos_end.y = label->pos.y + label->size.y;
      pos_end.z = label->pos.z;
      draw_rectangle(zpx, &label->pos, &pos_end, label->bg);
    }
  set.pix = zpx;
  set.font = label->font;
  set.pos = label->pos;
  set.pos_end = label->pos_end;
  set.txt = label->text;
  set.font_color = label->font_color;
  eftext(&set);
}
