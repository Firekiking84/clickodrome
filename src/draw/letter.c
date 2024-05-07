#include                "label.h"

void                    efletter(t_letter_settings *set)
{
  t_bunny_clipable	tmp;

  bunny_clipable_copy(&tmp, &set->font->clipable);
  set->font->clipable.clip_x_position = set->c * set->font_size.x;
  set->font->clipable.clip_y_position = 0;
  set->font->clipable.clip_width = set->font_size.x;
  blit(set->pix, set->font, &set->pos, set->col);
  bunny_clipable_copy(&set->font->clipable, &tmp);
}
