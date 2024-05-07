#include		"draw.h"

#include		<stdlib.h>

int			main(void)
{
  t_bunny_pixelarray	px;
  t_bunny_pixelarray	*font;
  t_bunny_window	*win;
  t_bunny_position	posEnd;
  t_bunny_position	posStart;
  t_bunny_position	origin;
  t_bunny_color		color;
  int			i;

  bunny_set_memory_check(true);
  bunny_set_maximum_ram(20 * 1024 * 1024);
  srand(0);

  origin.x = 0;
  origin.y = 0;
  win = bunny_start(500, 500, false, "DrawProut");
  px = bunny_new_pixelarray(500, 500);
  posStart.x = 0;
  posStart.y = 0;
  posEnd.x = px->clipable.buffer.width;
  posEnd.y = px->clipable.buffer.height;
  while (posStart.x < px->clipable.buffer.width && posStart.y < px->clipable.buffer.height)
    {
      color.full = rand();
      // color.argb[ALPHA_CMP] = 200;
      draw_rectangle(&px, &posStart, &posEnd, &color);
      bunny_blit(&win->buffer, &px->clipable, &origin);
      bunny_display(win);
      usleep(500);
      posStart.x += 1;
      posStart.y += 1;
      posEnd.y -= 1;
      posEnd.x -= 1;
    }
  i = 0;
  while (i < 1000)
    {
      posStart.x = rand() % px->clipable.buffer.width;
      posStart.y = rand() % px->clipable.buffer.height;
      posEnd.x = rand() % px->clipable.buffer.width;
      posEnd.y = rand() % px->clipable.buffer.height;
      color.full = rand();
      // color.argb[ALPHA_CMP] = 255;
      draw_rectangle(&px, &posStart, &posEnd, &color);
      bunny_blit(&win->buffer, &px->clipable, &origin);
      bunny_display(win);
      i += 1;
      usleep(500);
    }
  /*  posStart.x = 0;
  posStart.y = 0;
  font = bunny_load_pixelarray("font.png");
  blit(&px, font, &posStart, &color);
  bunny_blit(&win->buffer, &px->clipable, &origin);
  bunny_display(win); */
  bunny_delete_clipable(&px->clipable);
  usleep(500);
}
