#include            <lapin.h>
#include	    "draw.h"
void                eftext(t_text_settings *set)
{
  int		    i;
  t_zposition	    po;
  t_letter_settings sett;

  po.x = set->pos->x;
  po.y = set->pos->y;
  i = 0;
  while (set->txt[i] != '\0')
    {
      if (set->txt[i] == '\n')
	{
	  set->pos->x = po.x;
	  set->pos->y += 15;
	}
      else
	{
	  efletter(&sett);
	  set->pos->x += 12;
	}
      i ++;
    }
  *set->pos = po;
}
