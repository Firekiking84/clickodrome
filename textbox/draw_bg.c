#include		"text_box.h"

void			draw_bg(t_text_box			*text_box,
				t_bunny_zpixelarray		*px)
{
  t_zposition		end_pos;

  if (text_box->bg)
    {
      end_pos.z = text_box->pos.z;
      end_pos.x = text_box->pos.x + text_box->size.x;
      end_pos.y = text_box->pos.y + text_box->size.y;
      draw_rectangle(px, &text_box->pos, &end_pos, text_box->bg);
    }
}
