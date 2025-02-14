#include "diagram.h"

diagram_t* diagram_fill_image(diagram_t* context, image_t* image) {
  context->fn_fill_image(context, image);
  return context;
}
