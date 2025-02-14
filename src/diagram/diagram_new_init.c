#include "diagram.h"

diagram_t* diagram_new_init(diagram_t** context, diagram_init_t* init) {
  if (!context)
    return NULL;
  if (!init)
    return diagram_new(context);
  *context = (diagram_t*)malloc(sizeof(diagram_t));
  if (!*context)
    return NULL;

  **context = (diagram_t){
    .status = DIAGRAM_STATUS_INIT,
    .frame = init->frame,
    .boundary = init->boundary,
    .num_point = init->frame.width * init->frame.height,

    .fn_coordinate_new = (init->fn_coordinate_new)
      ? init->fn_coordinate_new 
      : diagram_fn_default_coordinate_new,
    .fn_coordinate_delete = (init->fn_coordinate_delete)
      ? init->fn_coordinate_delete
      : diagram_fn_default_coordinate_delete,
    .fn_coordinate_update = (init->fn_coordinate_update)
      ? init->fn_coordinate_update
      : diagram_fn_default_coordinate_update,

    .fn_data_point_new = (init->fn_data_point_new)
      ? init->fn_data_point_new
      : diagram_fn_default_data_point_new,
    .fn_data_point_delete = (init->fn_data_point_delete)
      ? init->fn_data_point_delete
      : diagram_fn_default_data_point_delete,

    .fn_each = init->fn_each,
    .fn_fill_image = init->fn_fill_image
  };

  (*context)->fn_coordinate_new(*context);
  (*context)->fn_data_point_new(*context);
  (*context)->fn_coordinate_update(*context);

  return *context;
}
