#ifndef DIAGRAM_H
#define DIAGRAM_H

#include "image.h"
#include "pointer.h"
#include "runtime.h"
#include "type.h"
#include "vector.h"

#define DIAGRAM_STATUS_INIT 0
#define DIAGRAM_STATUS_DONE 1
#define DIAGRAM_STATUS_WORK 2

typedef struct diagram_s      diagram_t;
typedef struct diagram_init_s diagram_init_t;

struct diagram_s {
  u32_t status;

  v2_u32_t frame;
  v4_f64_t boundary; 

  u64_t num_point;

  u32_t bytes_per_coordinate;
  u32_t bytes_per_data_point;

  ptr_t map_coordinate;
  ptr_t map_data_point;

  runtime_t runtime;

  // function: coordinate
  void (*fn_coordinate_new)(diagram_t*);
  void (*fn_coordinate_delete)(void*);
  void (*fn_coordinate_update)(diagram_t*);
  // function: data point
  void (*fn_data_point_new)(diagram_t*);
  void (*fn_data_point_delete)(void*);
  // function: run
  void (*fn_each)(void*, ptr_t*, ptr_t*);
  // function: image
  void (*fn_fill_image)(diagram_t*, image_t*);
  //void (*fn_to_image)(diagram_t*, image_t**);
};

struct diagram_init_s {
  v2_u32_t frame;
  v4_f64_t boundary;

  // function: coordinate
  void (*fn_coordinate_new)(diagram_t*);
  void (*fn_coordinate_delete)(void*);
  void (*fn_coordinate_update)(diagram_t*);
  // function: data point
  void (*fn_data_point_new)(diagram_t*);
  void (*fn_data_point_delete)(void*);
  // function: run
  void (*fn_each)(void*, ptr_t*, ptr_t*);
  // function: image
  void (*fn_fill_image)(diagram_t*, image_t*);
};

//------------------------------------------------------------------------------
// CONSTRUCTOR
//------------------------------------------------------------------------------

diagram_t* diagram_new(diagram_t** context);
diagram_t* diagram_new_init(diagram_t** context, diagram_init_t* init);

//------------------------------------------------------------------------------
// DESTRUCTOR
//------------------------------------------------------------------------------

void diagram_delete(void* context);

//------------------------------------------------------------------------------
// METHODS
//------------------------------------------------------------------------------

void diagram_fn_default_coordinate_new(diagram_t* context);
void diagram_fn_default_coordinate_delete(void* context);
void diagram_fn_default_coordinate_update(diagram_t* context);

void diagram_fn_default_data_point_new(diagram_t* context);
void diagram_fn_default_data_point_delete(void* context);

diagram_t* diagram_mouve(diagram_t* context, v2_f64_t* direction);
diagram_t* diagram_run(diagram_t* context, void* arg);
diagram_t* diagram_fill_image(diagram_t* context, image_t* image);
diagram_t* diagram_zoom(diagram_t* context, v2_u32_t focus, f64_t scale);

#endif
