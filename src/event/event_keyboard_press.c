#include "fractol.h"

#include <stdio.h>

int event_keyboard_press(int keycode, void *param) {

  printf("keycode press: %i\n", keycode);
  (void)keycode;
  (void)param;
}
