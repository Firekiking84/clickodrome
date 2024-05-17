#include		"clickodrome.h"

static void		init_label_settings(t_label_settings	*set)
{
  set->pos.x = -1;
  set->pos.y = -1;
  set->size.x = -1;
  set->size.y = -1;
  set->name = efstrdup("memo");
  set->text = NULL;
  set->font_name = NULL;
  set->font_res = NULL;
  set->font_size.x = -1;
  set->font_size.y = -1;
  set->font_color = NULL;
  set->bg = NULL;
}

void			edit_note(t_gui		*gui,
				  void		*data,
				  const char	*entry)
{
  t_label_settings	set;

  init_label_settings(&set);
  set.text = efstrdup(entry);
  efedit_label_gui(gui, "memo", &set);
  bunny_free(set.name);
}
