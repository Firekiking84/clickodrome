#include		"draw.h"

#include		<stdlib.h>

int			main(void)
{
  t_bunny_zpixelarray	px;
  t_bunny_pixelarray	*font;
  t_bunny_window	*win;
  t_zposition		posEnd;
  t_zposition		posStart;
  t_bunny_position	origin;
  t_bunny_color		color;
  int			i;

  bunny_set_memory_check(true);
  bunny_set_maximum_ram(20 * 1024 * 1024);
  srand(0);

  origin.x = 0;
  origin.y = 0;
  win = bunny_start(500, 500, false, "DrawProut");
  px.px = bunny_new_pixelarray(500, 500);
  px.z = bunny_malloc(sizeof(double) * (500 * 500));
  i = 0;
  while (i < (500 * 500))
    {
      px.z[i] = 1000000000010;
      i += 1;
    }
  posStart.x = 0;
  posStart.y = 0;
  posStart.z = 1000;
  posEnd.x = px.px->clipable.buffer.width;
  posEnd.y = px.px->clipable.buffer.height;
  posEnd.z = 1000;
  while (posStart.x < px.px->clipable.buffer.width && posStart.y < px.px->clipable.buffer.height)
    {
      color.full = rand();
      // color.argb[ALPHA_CMP] = 200;
      draw_rectangle(&px, &posStart, &posEnd, &color);
      bunny_blit(&win->buffer, &px.px->clipable, &origin);
      bunny_display(win);
      usleep(500);
      posStart.x += 1;
      posStart.y += 1;
      posStart.z -= 1;
      posEnd.y -= 1;
      posEnd.x -= 1;
      posEnd.z -= 1;
    }
  i = 0;
  while (i < 1000)
    {
      posStart.x = rand() % px.px->clipable.buffer.width;
      posStart.y = rand() % px.px->clipable.buffer.height;
      posStart.z = rand() % 2000;
      posEnd.z = posStart.z;
      posEnd.x = rand() % px.px->clipable.buffer.width;
      posEnd.y = rand() % px.px->clipable.buffer.height;
      color.full = rand();
      // color.argb[ALPHA_CMP] = 255;
      draw_rectangle(&px, &posStart, &posEnd, &color);
      bunny_blit(&win->buffer, &px.px->clipable, &origin);
      bunny_display(win);
      i += 1;
      usleep(500);
    }
  /*  posStart.x = 0;
  posStart.y = 0;
  font = bunny_load_pixelarray("font.png");
  blit(&px, font, &posStart, &color);
  bunny_blit(&win->buffer, &px.px->clipable, &origin);
  bunny_display(win); */
  bunny_delete_clipable(&px.px->clipable);
  bunny_free(px.z);
  usleep(500);
}
