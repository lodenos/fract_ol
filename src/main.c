#include "fractol.h"
#include "state.h"

int main(int argc, char** argv) {
  state_t state;
  v2_u32_t frame;
  (void)argc;
  (void)argv;

  frame = (v2_u32_t){ .width = 1920, .height = 1080 };

  state.display = XOpenDisplay(NULL);
  state.screen_number = XDefaultScreen(state.display);
  state.root = XRootWindow(state.display, state.screen_number);
  state.window = XCreateSimpleWindow(state.display, state.root,
    0, 0, frame.width, frame.height, 0, 0, 0);

  XStoreName(state.display, state.window, "fract_ol X11");

  if (!image_new_init(&state.image, &(image_init_t){
      .frame = frame, .bytes_per_pixel = 4 })) {
    return 0;
  }

  state.ximage = XCreateImage(
    state.display,
    CopyFromParent,
    (unsigned int)DefaultDepth(state.display, DefaultScreen(state.display)),
    ZPixmap, 0,
    state.image->data,
    (unsigned int)state.image->width,
    (unsigned int)state.image->height,
    8,
    (int)state.image->bytes_per_line);

  state.graphic_context = XCreateGC(state.display, state.window, 0, NULL);

  XMapWindow(state.display, state.window);
  XSync(state.display, False);
  XSelectInput(state.display, state.window,
    KeyPressMask | KeyReleaseMask |
    ButtonPressMask | ButtonReleaseMask | PointerMotionMask |
    ExposureMask | StructureNotifyMask);

  event_loop(&state);

  return 0;
}
