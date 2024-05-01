#include		"label.h"

void                    efdisplay_label(t_label                 *labelt,
					t_bunny_zpixelarray     *zpx,
					t_bunny_pixelarray	*font)
{
  t_zposition		pos_end;
  t_label               label;

  label = *labelt;
  if (label.bg != NULL)
    {
      pos_end.x = label.pos.x + label.size.x;
      pos_end.y = label.pos.y + label.size.y;
      pos_end.z = label.pos.z;
      draw_rectangle(zpx, &label.pos, &pos_end, label.bg);
    }
  eftext(zpx, font, &label.pos, label.text, label.font_color);
  label.pos.y -= 12;
  eftext(zpx, font, &label.pos, label.name, label.font_color);
}
