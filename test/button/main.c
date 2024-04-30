#include "button.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
typedef struct s_data
{
  
int main(void)
{

  t_bunny_pixelarray	 *px;
  t_bunny_pixelarray	 *front;
  t_bunny_window 	 *win;
  t_bunny_position	 posStart;
  t_bunny_position	 posEnd;
  t_bunny_position	 origin;
  int			 i;
  t_data		 data;
  t_bunny_zpixelarray    *px;
  t_zposition		 pos;
  t_bunny_size		 size;
  const char		 *name;
  const char		 *text;
  bool			 focus;
  bool			 in_button;
  t_bunny_color		 font_color;
  t_bunny_color		 hover_color;
  t_bunny_color		 bg;
  t_vector		 function;

  srand(0);

  origine.x = 0;
  origine.y = 0;
  win =  bunny_start(500, 5, false, "DrawProut");
  px = bunny_new_pixelarray(500, 5);
  posStart.x = 0;
  posStart.y = 0;
  posEnd.x = px->clipable.buffer.width;
  posEnd.y = px->clipable.buffer.height;
  //data.button = efnew_button(pos , size,name ,texte ,focus ,inbutton ,font_color ,hover_color ,bg ,function);
  bunny_delete_clipable(&px->clipable);
  posStart.x = 0;
  posStart.y = 0;
  font = bunny_load_pixelarray("font.png");
  blit(px, font, &posStart, &color);
  bunny_blit(&win->buffer, &px->clipable, &origin);
  bunny_display(win);
  usleep(5000);
}
