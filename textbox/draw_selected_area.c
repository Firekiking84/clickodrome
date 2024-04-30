#include		"text_box.h"

void			draw_selected_area(t_text_box		*text_box,
					   t_zposition		pos_start,
					   t_bunny_zpixelarray	*px)
{
  t_zposition		end;
  t_bunny_color		selected_col;

  end.z = pos_start.z;
  end.x = pos_start.x + text_box->size_font.x;
  end.y = pos_start.y + text_box->size_font.y;
  selected_col.full = BLUE;
  draw_rectangle(px, &pos_start, &end, &selected_col);
}
