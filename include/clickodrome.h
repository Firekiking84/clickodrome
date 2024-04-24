#ifndef			__CLICKODROME_H__
#define			__CLICKODROME_H__

#include		"gui.h"

typedef struct          s_bunny_zpixelarray
{
  t_bunny_pixelarray    *px;
  double                *z;
}		        t_bunny_zpixelarray

typedef struct          s_program
{
  t_bunny_zpixelarray   *zpx;
  t_bunny_pixelarray	*font;
  t_bunny_window	*window;
  t_gui			*gui;
}			t_program

t_bunny_response        display_function(void                           *data);

t_bunny_response        loop_function(void                              *data);

#endif//		__CLICKODROME_H__
