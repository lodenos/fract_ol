#ifndef IMAGE_H
#define IMAGE_H

#include "vector.h"

typedef struct image_s      image_t;
typedef struct image_init_s image_init_t;

struct image_s {
  union {
    v2_u32_t frame;
    struct {
      u32_t width;
      u32_t height;
    };
  };

  u32_t bytes_per_line;
  u32_t bytes_per_pixel;

  void* data;
  u64_t data_size;
};

struct image_init_s {
  union {
    v2_u32_t frame;
    struct {
      u32_t width;
      u32_t height;
    };
  };

  u32_t bytes_per_pixel;
};

//------------------------------------------------------------------------------
// CONSTRUCTOR
//------------------------------------------------------------------------------

image_t* image_new(image_t** context);
image_t* image_new_init(image_t** context, image_init_t* init);

//------------------------------------------------------------------------------
// DESTRUCTOR
//------------------------------------------------------------------------------

void image_delete(void* context);

#endif
