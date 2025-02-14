#include <stdlib.h>
#include "image.h"

image_t* image_new(image_t** context) {
  *context = (image_t*)malloc(sizeof(image_t));
  **context = (image_t){0};
  return *context;
}
