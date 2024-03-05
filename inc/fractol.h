#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <mlx_int.h>

typedef struct s_complex t_complex;
typedef struct s_state t_state;

struct s_complex {
  double imag;
  double real;
};

struct s_state {
  void *img_ptr;
  void *mlx_ptr;
  void *win_ptr;
};

enum e_event {
  ON_KEY_PRESS         = 2,
  ON_KEY_RELEASE       = 3,
  ON_BUTTON_PRESS      = 4,
  ON_BUTTON_RELEASE    = 5,
  ON_MOTION_NOTIFY     = 6,
  ON_ENTER_NOTIFY      = 7,
  ON_LEAVE_NOTIFY      = 8,
  ON_FOCUS_IN          = 9,
  ON_FOCUS_OUT         = 10,
  ON_KEYMAP_NOTIFY     = 11,
  ON_EXPOSE            = 12,
  ON_GRAPHICS_EXPOSE   = 13,
  ON_NO_EXPOSE         = 14,
  ON_VISIBILITY_NOTIFY = 15,
  ON_CREATE_NOTIFY     = 16,
  ON_DESTROY_NOTIFY    = 17,
  ON_UNMAP_NOTIFY      = 18,
  ON_MAP_NOTIFY        = 19,
  ON_MAP_REQUEST       = 20,
  ON_REPARENT_NOTIFY   = 21,
  ON_CONFIGURE_NOTIFY  = 22,
  ON_CONFIGURE_REQUEST = 23,
  ON_GRAVITY_NOTIFY    = 24,
  ON_RESIZE_REQUEST    = 25
};

enum e_mask {
  NO_EVENT              = 0L,
  KEY_PRESS             = 1L << 0,
  KEY_RELEASE           = 1L << 1,
  BUTTON_PRESS          = 1L << 2,
  BUTTON_RELEASE        = 1L << 3,
  ENTER_WINDOW          = 1L << 4,
  LEAVE_WINDOW          = 1L << 5,
  POINTER_MOTION        = 1L << 6,
  POINTER_MOTION_HINT   = 1L << 7,
  BUTTON_1_MOTION       = 1L << 8,
  BUTTON_2_MOTION       = 1L << 9,
  BUTTON_3_MOTION       = 1L << 10,
  BUTTON_4_MOTION       = 1L << 11,
  BUTTON_5_MOTION       = 1L << 12,
  BUTTON_MOTION         = 1L << 13,
  KEYMAP_STATE          = 1L << 14,
  EXPOSURE              = 1L << 15,
  VISIBILITY_CHANGE     = 1L << 16,
  STRUCTURE_NOTIFY      = 1L << 17,
  RESIZE_REDIRECT       = 1L << 18,
  SUBSTRUCTURE_NOTIFY   = 1L << 19,
  SUBSTRUCTURE_REDIRECT = 1L << 20,
  FOCUS_CHANGE          = 1L << 21,
  PROPERTY_CHANGE       = 1L << 22,
  COLORMAP_CHANGE       = 1L << 23,
  OWNER_GRAB_BUTTON     = 1L << 24
};

void event(t_state *);
int event_keyboard_press(int, void *);
int event_keyboard_release(int, void *);
int event_mouse_click_press(int, int, int, void *);
int event_mouse_click_release(int, int, int, void *);
int event_mouse_nouve(int, int, void *);

#endif
