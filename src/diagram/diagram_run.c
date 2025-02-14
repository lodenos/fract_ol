#include "diagram.h"

#include <stdio.h>

diagram_t* diagram_run(diagram_t* context, void* arg) {
  runtime_start(&context->runtime);
  context->fn_each(arg, &context->map_coordinate, &context->map_data_point);
  runtime_stop(&context->runtime);

  printf("> diagram_run: %ld us\n", context->runtime.delta);

  return context;
}
