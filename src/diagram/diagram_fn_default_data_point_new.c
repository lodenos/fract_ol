#include "diagram.h"

void diagram_fn_default_data_point_new(diagram_t *context) {
  malloc_ptr(&context->map_data_point, sizeof(v2_f64_t) * context->num_point);
  if (!context->map_data_point.start)
    return ;
  context->bytes_per_coordinate = sizeof(v2_f64_t);

}
