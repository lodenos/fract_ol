#include "diagram.h"

void diagram_fn_default_coordinate_new(diagram_t* context) {
  malloc_ptr(&context->map_coordinate, sizeof(v2_f64_t) * context->num_point);
  if (!context->map_coordinate.start)
    return ;
  context->bytes_per_coordinate = sizeof(v2_f64_t);
}
