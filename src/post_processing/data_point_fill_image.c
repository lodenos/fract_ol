#include "fractal.h"
#include "post_processing.h"

void data_point_fill_image(diagram_t* context, image_t* image) {
  fractal_data_point_t* reference;
  fractal_data_point_t* reference_stop;
  rgba8_t* img;

  reference = (fractal_data_point_t*)context->map_data_point.start;
  reference_stop = (fractal_data_point_t*)context->map_data_point.stop;
  img = image->data;
  while (reference < reference_stop) {
    *img = hsla8_to_rgba8((hsla8_t){
      .h = (u8_t)reference->num_recursion,
      .s = 127,
      .l = 127,
      .a = 0
    });
    ++img;
    ++reference;
  }
}
