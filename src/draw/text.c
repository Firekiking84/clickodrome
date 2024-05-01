#include            <lapin.h>

void                eftext(t_bunny_zpixelarray		*pix,
                           t_bunny_pixelarray		*font,
			   t_zposition			*pos,
			   const char			*txt,
			   t_bunny_color		*font_color)
{
  int             i;
  t_zposition	  po;

  po.x = pos->x;
  po.y = pos->y;
  i = 0;
  while (txt[i] != '\0')
    {
      if (txt[i] == '\n')
	{
	  pos->x = po.x;
	  pos->y += 15;
	}
      else
	{
	  efletter(pix, font, pos, font_color, txt[i]);
	  pos->x += 12;
	}
      i ++;
    }
  *pos = po;
}
