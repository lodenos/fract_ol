#include "fractol.h"

int main(void) {
  t_state state;

  state.mlx_ptr = mlx_init();
  state.win_ptr = mlx_new_window(state.mlx_ptr, 2000, 2000, "fractol");
  state.img_ptr = mlx_new_image(state.mlx_ptr, 2000, 2000);

  event(&state);

  mlx_loop(state.mlx_ptr);

  mlx_destroy_image(state.mlx_ptr, state.img_ptr);
  mlx_destroy_window(state.mlx_ptr, state.win_ptr);
  free(state.mlx_ptr);
  return 0;
}
