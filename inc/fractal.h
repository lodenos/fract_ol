#ifndef FRACTAL_H
#define FRACTAL_H

#include "complex.h"
#include "diagram.h"
#include "pointer.h"

typedef struct fractal_context_s    fractal_context_t;
typedef struct fractal_data_point_s fractal_data_point_t;

struct fractal_context_s {
  c64_t complex;
  u32_t max_recursion;

  u64_t num_point;
};

struct fractal_data_point_s {
  c64_t complex;
  f64_t absolute;
  u64_t num_recursion;
};

void fractal_data_point_new(diagram_t* context);

void fractal_mandelbrot(void* arg, ptr_t* map, ptr_t* data_point);

#endif
