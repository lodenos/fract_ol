#include <stdlib.h>
#include "diagram.h"

diagram_t* diagram_new(diagram_t** context) {
  if (!context)
    return NULL;
  *context = (diagram_t*)malloc(sizeof(diagram_t));
  if (!*context)
    return NULL;

  // TODO:

  return *context;
}
