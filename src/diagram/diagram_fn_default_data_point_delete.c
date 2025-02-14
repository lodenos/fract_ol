#include "diagram.h"

void diagram_fn_default_data_point_delete(void* context) {
  free(context);
}
