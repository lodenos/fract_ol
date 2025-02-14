#include "fractal.h"

void fractal_data_point_new(diagram_t* context) {
  malloc_ptr(&context->map_data_point, sizeof(fractal_data_point_t) * context->num_point);
  if (!context->map_data_point.start)
    return ;
  context->bytes_per_coordinate = sizeof(fractal_data_point_t);
}
