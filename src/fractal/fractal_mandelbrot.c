#include "fractal.h"

#include <stdio.h>

static __inline__ void formula(fractal_context_t* context, c64_t* coordinate,
    fractal_data_point_t* data_point) {
  c64_t z;
  u32_t itr;

  z = *coordinate;
  itr = 0;
  while ((itr < context->max_recursion) && (c64_abs_2(z) < (f64_t)4.0)) {
    z = c64_add(c64_mul(z,z), *coordinate);
    ++itr;
  }
  *data_point = (fractal_data_point_t){
    .complex = z,
    .absolute = c64_abs(z),
    .num_recursion = itr
  };
}

void fractal_mandelbrot(void* arg, ptr_t* map, ptr_t* data_point) {
  fractal_context_t* context = (fractal_context_t*)arg;
  fractal_data_point_t* point;
  c64_t* complex_plan;

  point = (fractal_data_point_t*)data_point->start;
  complex_plan = (c64_t*)map->start;
  while (complex_plan < (c64_t*)map->stop)
    formula(context, complex_plan++, point++);
}
