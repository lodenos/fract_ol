#include <stdlib.h>
#include "image.h"

void image_delete(void* context) {
  free(((image_t*)context)->data);
  free(context);
}
