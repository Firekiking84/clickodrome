#include		"label.h"

static void		ecriture_texte(t_bunny_zpixelarray		*zpx,
				       t_label				*label,
				       int				x,
				       t_bunny_pixelarray		*font)
{
  int			xt;
  t_zposition		po;

  xt = 0;
  po.x = label->pos.x;
  po.y = label->pos.y;
  while (label->text[xt] != '\0')
    {
      if (label->text[xt] == '\n')
	{
	  po.x = label->pos.x;
	  po.y += 15;
	}
      else if (po.x + 10 <= x - 10)
	{
	  efletter(zpx, font, &po, label->font_color, label->text[xt]);
	  po.x += 12;
	}
      xt ++;
    }
}

void                    efdisplay_label(t_label                 *labelt,
					t_bunny_zpixelarray     *zpx,
					t_bunny_pixelarray	*font)
{
  t_zposition		pos_end;
  t_label               label;
  t_letter_settings	set;

  label = *labelt;
  pos_end.x = (label.pos.x + label.size.x);
  if (label.bg != NULL)
    {
      pos_end.y = label.pos.y + label.size.y;
      pos_end.z = label.pos.z;
      draw_rectangle(zpx, &label.pos, &pos_end, label.bg);
    }
  ecriture_texte(&set);
}
