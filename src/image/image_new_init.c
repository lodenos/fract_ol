#include <stdlib.h>
#include "image.h"

image_t* image_new_init(image_t** context, image_init_t* init) {
  if (!init)
    return image_new(context);
  if (!init->bytes_per_pixel || !init->width || !init->height)
    return NULL;
  *context = (image_t*)malloc(sizeof(image_t));
  if (!*context)
    return NULL;
  **context = (image_t){
    .frame = init->frame,
    .bytes_per_line = init->width * init->bytes_per_pixel,
    .bytes_per_pixel = init->bytes_per_pixel,
    .data_size = init->height * init->width * init->bytes_per_pixel
  };
  (*context)->data = malloc((*context)->data_size);
  if (!(*context)->data)
    return free(*context), NULL;
  return *context;
}
