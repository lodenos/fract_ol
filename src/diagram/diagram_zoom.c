#include "diagram.h"

diagram_t* diagram_zoom(diagram_t* context, v2_u32_t focus, f64_t scale) {
  v2_f64_t range;
  v2_f64_t pixel;
  v2_f64_t point;

  range = (v2_f64_t){
    .x = context->boundary.bx - context->boundary.ax,
    .y = context->boundary.by - context->boundary.ay
  };
  pixel = (v2_f64_t){
    .x = range.x / (f64_t)context->frame.width,
    .y = range.y / (f64_t)context->frame.height
  };
  point = (v2_f64_t){
    .x = context->boundary.ax + (pixel.x * (f64_t)focus.x),
    .y = context->boundary.ay + (pixel.y * (f64_t)focus.y)
  };
  context->boundary.va = (v2_f64_t){
    .x = point.x - ((pixel.x / scale) * (f64_t)focus.x),
    .y = point.y - ((pixel.y / scale) * (f64_t)focus.y)
  };
  context->boundary.vb = (v2_f64_t){
    .x = context->boundary.ax + ((pixel.x / scale) * (f64_t)context->frame.width),
    .y = context->boundary.ay + ((pixel.y / scale) * (f64_t)context->frame.height)
  };
  context->fn_coordinate_update(context);
  return context;
}
