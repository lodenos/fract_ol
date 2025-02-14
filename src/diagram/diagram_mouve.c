#include "diagram.h"

// INFO: direction is a vector, every 1 is 100% size of map shift

diagram_t* diagram_mouve(diagram_t* context, v2_f64_t* direction) {
  v2_f64_t range;
  v2_f64_t shift;

  range = (v2_f64_t){
    .x = context->boundary.bx - context->boundary.ax,
    .y = context->boundary.by - context->boundary.ay
  };
  shift = (v2_f64_t){
    .x = range.x * direction->x,
    .y = range.y * direction->y
  };
  context->boundary = (v4_f64_t){
    .ax = context->boundary.ax + shift.x,
    .ay = context->boundary.ay + shift.y,
    .bx = context->boundary.bx + shift.x,
    .by = context->boundary.by + shift.y
  };
  context->fn_coordinate_update(context);
  return context;
}
