#include "fractol.h"

void event(t_state *state) {
  void *win = state->win_ptr;

  mlx_hook(win, ON_KEY_PRESS, KEY_PRESS, event_keyboard_press, state);
  mlx_hook(win, ON_KEY_RELEASE, KEY_RELEASE, event_keyboard_release, state);
  mlx_hook(win, ON_BUTTON_PRESS, BUTTON_PRESS, event_mouse_click_press, state);
  mlx_hook(win, ON_BUTTON_RELEASE, BUTTON_RELEASE, event_mouse_click_release, state);
  mlx_hook(win, ON_MOTION_NOTIFY, POINTER_MOTION, event_mouse_nouve, state);
}
