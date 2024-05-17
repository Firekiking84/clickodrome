#include		"clickodrome.h"

#include		<time.h>
#include		<stdio.h>

static void		init_label_settings(t_label_settings	*set)
{
  set->pos.x = -1;
  set->pos.y = -1;
  set->size.x = -1;
  set->size.y = -1;
  set->name = efstrdup("clock");
  set->text = NULL;
  set->font_name = NULL;
  set->font_res = NULL;
  set->font_size.x = -1;
  set->font_size.y = -1;
  set->font_color = NULL;
  set->bg = NULL;
}

void			refresh_time(t_gui			*gui,
				     void			*data)
{
  time_t		current_time;
  struct tm		*local_time;
  t_label_settings	set;

  init_label_settings(&set);
  time(&current_time);
  local_time = localtime(&current_time);
  set.text = bunny_malloc(sizeof(char) * 6); // 00:00\0
  if (!set.text)
    return;
  snprintf(set.text, 6, "%02d:%02d", local_time->tm_hour, local_time->tm_min);
  efedit_label_gui(gui, "clock", &set);
  bunny_free(set.name);
}
