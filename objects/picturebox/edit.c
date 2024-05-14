/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 14/05/2024 16:31:57 ******************************************************
** kenan.guidat <kenan.guidat@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"picture.h"

void			efedit_picture(t_picture		*picture,
				       t_picture_settings const	*edit)
{
  t_bunny_pixelarray	*new_res;

  if (edit->pos.x >= 0)
    picture->pos = edit->pos;
  if (edit->size.x > 0)
    picture->size = edit->size;
  if (edit->filename)
    {
      new_res = bunny_load_pixelarray(edit->filename);
      if (new_res)
	{
	  bunny_delete_clipable(picture->img);
	  picture->img = new_res;
	}
    }
}
