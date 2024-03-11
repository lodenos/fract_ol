#include <stdlib.h>
#include "color.h"
#include "fractol.h"

int on_destroy(void *param) {
  (void)param;
  exit(EXIT_SUCCESS);
  return 0;
}

void event(t_state *state) {
  void *win = state->win_ptr;

  // 1920, 1080

  int x;
  int y;
  int max = 1000;
  int itr;
  t_complex z;
  t_complex c = (t_complex){-2, -2};

  int q, w, e;;

  t_rgb *img = mlx_get_data_addr(state->img_ptr, &q, &w, &e);

  y = 0;
  while (y < 2000) {
    x = 0;
    c.re = -2;
    while (x < 2000) {
      itr = 0;
      z = (t_complex){0};
      while (complex_modulus_2(&z) < 4 && itr < max) {
        z = complex_mul(&z, &z);
        z = complex_add(&z, &c);
        ++itr;
      }
//      if (itr == max) {
//        mlx_pixel_put(state->mlx_ptr, state->win_ptr, x, y, 0xFFFFFFFF);
      img[y * 2000 + x] = color_hsl_to_rgb(&(t_hsl){
        .hue = itr,
        .saturation = 0.5,
        .lightness = 0.1
      });
      c.re += 0.001;
      ++x;
    }
    c.im += 0.001;
    ++y;
  }

  printf(">>----------\n");

  mlx_put_image_to_window(state->mlx_ptr, state->win_ptr, state->img_ptr, 0, 0);

  mlx_hook(win, ON_KEY_PRESS, KEY_PRESS, event_keyboard_press, state);
  mlx_hook(win, ON_KEY_RELEASE, KEY_RELEASE, event_keyboard_release, state);
  mlx_hook(win, ON_BUTTON_PRESS, BUTTON_PRESS, event_mouse_click_press, state);
  mlx_hook(win, ON_BUTTON_RELEASE, BUTTON_RELEASE, event_mouse_click_release, state);
  mlx_hook(win, ON_MOTION_NOTIFY, POINTER_MOTION, event_mouse_nouve, state);
  mlx_hook(win, ON_DESTROY_NOTIFY, STRUCTURE_NOTIFY, on_destroy, state);
  // start-up
}
