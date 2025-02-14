#include "diagram.h"
#include "vector.h"

#include <stdio.h>

void diagram_fn_default_coordinate_update(diagram_t* context) {
  v2_u32_t itr;
  v2_f64_t point;
  v2_f64_t* map;
  const v2_f64_t pixel_size = (v2_f64_t){
    .x = (context->boundary.bx - context->boundary.ax) / context->frame.width,
    .y = (context->boundary.by - context->boundary.ay) / context->frame.height
  };

  map = (v2_f64_t*)context->map_coordinate.start;
  point.y = context->boundary.ay;
  itr.y = 0;
  while (itr.y < context->frame.height) {
    point.x = context->boundary.ax;
    itr.x = 0;
    while (itr.x < context->frame.width) {
      map->x = point.x;
      map->y = point.y;
      point.x += pixel_size.x;
      ++map;
      ++itr.x;
    }
    point.y += pixel_size.y;
    ++itr.y;
  }
}
