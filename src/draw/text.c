#include            <lapin.h>
#include	    "draw.h"

void                eftext(t_text_settings *set)
{
  int		    i;
  t_letter_settings sett;

  sett.pix = set->pix;
  sett.font = set->font;
  sett.font_size = set->font_size;
  sett.pos = set->pos;
  sett.col = set->font_color;
  i = 0;
  while (set->txt[i] != '\0')
    {
      sett.c = set->txt[i];
      if (set->txt[i] == '\n')
	{
	  sett.pos.x = set->pos.x;
	  sett.pos.y += set->font_size.y + 1;
	  if ((sett.pos.y + set->font_size.y) > set->pos_end.y)
	     return;
	}
      else
	{
	  efletter(&sett);
	  sett.pos.x += set->font_size.x + 1;
	  if ((sett.pos.x + set->font_size.x) > set->pos_end.x)
	    {
	      sett.pos.x = set->pos.x;
	      sett.pos.y += set->font_size.y + 1;
	      if ((sett.pos.y + set->font_size.y) > set->pos_end.y)
		return;
	    }
	}
      i ++;
    }
}
