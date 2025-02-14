#ifndef WINDOW_H
#define WINDOW_H

#include <X11/Xlib.h>

#include "type.h"
#include "vector.h"

typedef struct window_s window_t;
typedef struct window_init_s window_init_t;

struct window_s {
  Display* display;
  XImage*  ximage;
  GC       graphic_context;

  Window root;
  Window window;

  i32_t screen_number;
};

window_t* window_new(char* title, v2_u32_t frame);

#endif
