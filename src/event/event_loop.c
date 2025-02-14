#include <stdbool.h>
#include <X11/Xlib.h>
#include "diagram.h"
#include "event.h"
#include "post_processing.h"
#include "state.h"

#include "fractal.h"

#include <printf.h>

#define KEYBOARD_ARROW_LEFT  131
#define KEYBOARD_ARROW_RIGHT 132
#define KEYBOARD_ARROW_DOWN  133
#define KEYBOARD_ARROW_UP    134

#define KEYBOARD_ESCAPE 61

#define MOUSE_CLICK_LEFT  1
#define MOUSE_CLICK_WHEEL 2
#define MOUSE_CLICK_RIGHT 3
#define MOUSE_WHELL_UP    4
#define MOUSE_WHELL_DOWN  5

#define ZOOM_IN  1.1
#define ZOOM_OUT 0.9

// KEY for +- Max Iterations
// KEY for changing fractal 

static void keyboard_key_press(XEvent* event, state_t* state) {
  switch (event->xkey.keycode) {
  case KEYBOARD_ARROW_UP:
    diagram_mouve(state->diagram, &(v2_f64_t){ .x = 0, .y = 0.05 });
    state->update = true;
    break;
  case KEYBOARD_ARROW_LEFT:
    diagram_mouve(state->diagram, &(v2_f64_t){ .x = 0.05, .y = 0 });
    state->update = true;
    break;
  case KEYBOARD_ARROW_RIGHT:
    diagram_mouve(state->diagram, &(v2_f64_t){ .x = -0.05, .y = 0 });
    state->update = true;
    break;
  case KEYBOARD_ARROW_DOWN:
    diagram_mouve(state->diagram, &(v2_f64_t){ .x = 0, .y = -0.05 });
    state->update = true;
    break;
  case KEYBOARD_ESCAPE:
    state->running = 0;
    break;
  }
}

static void keyboard_key_release(XEvent* event, state_t* state) {
  (void)state;
 switch (event->xkey.keycode) {
  case KEYBOARD_ARROW_UP:
    break;
  case KEYBOARD_ARROW_LEFT:
    break;
  case KEYBOARD_ARROW_RIGHT:
    break;
  case KEYBOARD_ARROW_DOWN:
    break;
  case KEYBOARD_ESCAPE:
    break;
  }
}

static void mouse_button_press(XEvent* event, state_t* state) {
  (void)state;
 switch (event->xbutton.button) {
  case MOUSE_CLICK_LEFT:
    break;
  case MOUSE_CLICK_WHEEL:
    break;
  case MOUSE_CLICK_RIGHT:
    break;
  case MOUSE_WHELL_UP:
    break;
  case MOUSE_WHELL_DOWN:
    break;
  }
}

static void mouse_button_release(XEvent* event, state_t* state) {
  v2_u32_t position;

  position = (v2_u32_t){
    .x = (u32_t)event->xbutton.x,
    .y = (u32_t)event->xbutton.y
  };
  switch (event->xbutton.button) {
  case MOUSE_CLICK_LEFT:
    diagram_zoom(state->diagram, position, ZOOM_IN);
    state->update = true;
    break;
  case MOUSE_CLICK_WHEEL:
    break;
  case MOUSE_CLICK_RIGHT:
    diagram_zoom(state->diagram, position, ZOOM_OUT);
    state->update = true;
    break;
  case MOUSE_WHELL_UP:
    diagram_zoom(state->diagram, position, ZOOM_OUT);
    state->update = true;
    break;
  case MOUSE_WHELL_DOWN:
    diagram_zoom(state->diagram, position, ZOOM_IN);
    state->update = true;
    break;
  }
}

static void mouse_motion(XEvent* event, state_t* state) {
  (void)event;
  (void)state;
}

void event_loop(state_t* state) {
  XEvent event;
  XConfigureEvent xce;
  Atom wmDeleteMessage = XInternAtom(state->display,
    "WM_DELETE_WINDOW", False);
  XSetWMProtocols(state->display, state->window, &wmDeleteMessage, 1);

  state->running = 1;
  state->update = 0;

  printf("> Event loop: start\n");

  while (state->running) {
    XNextEvent(state->display, &event);
    switch (event.type) {
    case ClientMessage:
      if (event.xclient.data.l[0] == (long)wmDeleteMessage)
        state->running = 0;
      break;
    case ConfigureNotify:
      xce = event.xconfigure;
      printf("width: %d ; height: %d ; x: %d ; y: %d\n",
          xce.width, xce.height, xce.x, xce.y);
      break;
    case ButtonPress:
      mouse_button_press(&event, state);
      break;
    case ButtonRelease:
      mouse_button_release(&event, state);
      break;
    case Expose:
      printf("> Event > Expose\n");
      break;
    case KeyPress:
      keyboard_key_press(&event, state);
      break;
    case KeyRelease:
      keyboard_key_release(&event, state);
      break;
    case MapNotify:
      printf("> Event -> MapNotify\n");

      if (!state->diagram) {
        diagram_new_init(&state->diagram, &(diagram_init_t){
          .frame = (v2_u32_t){
            .width = 1920,
            .height = 1080
          },
          .boundary = (v4_f64_t){
            .ax = -2.0, .ay =  1.0,
            .bx =  2.0, .by = -1.0
          },
          .fn_data_point_new = fractal_data_point_new,
          .fn_each = fractal_mandelbrot,
          .fn_fill_image = data_point_fill_image
        });
        state->fractal_context.max_recursion = 20;
      }
      break;
    case MotionNotify:
      mouse_motion(&event, state);
      break;
    }

    if (state->update) {
      diagram_run(state->diagram, &state->fractal_context);
      diagram_fill_image(state->diagram, state->image);
      XPutImage(state->display, state->window, state->graphic_context,
        state->ximage, 0, 0, 0, 0,
        state->diagram->frame.width, state->diagram->frame.height);
      state->update = false;
    }
  }
}
