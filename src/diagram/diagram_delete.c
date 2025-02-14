#include "diagram.h"

void diagram_delete(void* context) {
  diagram_t const* reference = (diagram_t*)context;

  reference->fn_coordinate_delete(reference->map_coordinate.start);
  reference->fn_data_point_delete(reference->map_data_point.start);
}
