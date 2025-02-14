#ifndef STATE_H
#define STATE_H

#include <X11/Xlib.h>

#include "diagram.h"
#include "image.h"
#include "fractal.h"

typedef struct state_s state_t;

struct state_s {

  Display* display;

  Window root;
  Window window;

  image_t* image;
  XImage* ximage;

  GC    graphic_context;
  i32_t screen_number;

  u32_t running;

  u32_t update;

  diagram_t* diagram;
  fractal_context_t fractal_context;

};

#endif
