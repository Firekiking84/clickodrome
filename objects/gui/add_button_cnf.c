/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 14:41:56 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"gui.h"
#include		"efstring.h"

static const char		*font_already_load(const char		*fontname,
					  t_gui			*gui)
{
  size_t		i;
  const char*		font;

  i = 0;
  if (gui->divs->data_count == 1)
    efvector_ptr_push(gui->fonts,fontname);
  while (i < gui->divs->data_count)
    {
      font = efvector_ptr_get(gui->fonts, i);
      if (strcmp(fontname, font) == 0)
	{
	  efvector_ptr_push(gui->fonts,fontname);
	  return(font);
	}
      i += 1;
    }
  return(NULL);
}

static int		init_button_settings(t_bunny_configuration	*cnf,
					     t_button_settings		*settings,
					     t_gui			*gui)
{
  const char		*tmp;

  settings->gui = gui;
  settings->pos = efget_pos_cnf(cnf);
  settings->size = efget_size_cnf(cnf, "size");
  settings->order = gui->nb_input_components;
  gui->nb_input_components += 1;
  bunny_configuration_getf(cnf, &tmp, "name");
  if ((settings->name = efstrdup(tmp)) == NULL)
    return(-1);
  bunny_configuration_getf(cnf, &tmp, "text");
  if ((settings->text = efstrdup(tmp)) == NULL)
    {
      bunny_free(settings->name);
      return(-1);
    }
  bunny_configuration_getf(cnf, &tmp, "font");
  tmp = font_already_load(tmp,gui);
  settings->font = efstrdup(tmp);
  if (!settings->font)
    {
      bunny_free(settings->name);
      bunny_free(settings->text);
      return(-1);
    }
  settings->font_size = efget_size_cnf(cnf, "font_size");
  settings->click_color = efget_color_cnf(cnf, "click_color");
  settings->font_color = efget_color_cnf(cnf, "font_color");
  settings->bg = efget_color_cnf(cnf, "bg");
  settings->hover_color = efget_color_cnf(cnf, "hover_color");
  if ((settings->functions = efget_functions(cnf, gui)) == NULL)
    {
      bunny_free(settings->font);
      bunny_free(settings->name);
      bunny_free(settings->text);
      return(-1);
    }
  return(0);
}
int			efadd_button_cnf(t_bunny_configuration		*cnf,
					 t_gui				*gui)
{
  t_component		*comp;
  t_button_settings	settings;

  comp = bunny_malloc(sizeof(t_component));
  if (!comp)
    return(-1);
  if (init_button_settings(cnf, &settings,gui) == -1)
    {
      bunny_free(comp);
      return(-1);
    }
  comp->button = efadd_button_div(efvector_ptr_get(gui->divs, gui->divs->data_count - 1), &settings);
  if (!comp->button)
    {
      bunny_free(comp);
      bunny_free(settings.name);
      bunny_free(settings.text);
      return(-1);
    }
  comp->type = BUTTON;
  efvector_ptr_push(gui->components, comp);
  return(0);
}

