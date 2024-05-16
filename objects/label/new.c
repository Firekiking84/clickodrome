/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 14/05/2024 16:26:00 ******************************************************
** kenan.guidat <kenan.guidat@terechkova.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"label.h"
#include		"draw.h"

t_label			*efnew_label(t_label_settings	*settings)
{
  t_label		*label;

  if ((label =  bunny_malloc(sizeof(t_label))) == NULL)
    {
      perror(" bunny_malloc new_label");
      return (NULL);
    }
  label->pos = settings->pos;
  label->pos_end.x = settings->pos.x + settings->size.x;
  label->pos_end.y = settings->pos.y + settings->size.y;
  label->size = settings->size;
  label->name = settings->name;
  label->text = settings->text;
  if (!settings->font_name)
    label->font = settings->font_res;
  else
    label->font = bunny_load_pixelarray(settings->font_name);
  if (!label->font)
    {
      bunny_free(label->name);
      bunny_free(label->text);
      bunny_free(settings->font_color);
      bunny_free(settings->bg);
      return(NULL);
    }
  label->font_color = settings->font_color;
  label->bg = settings->bg;
  return(label);
}
