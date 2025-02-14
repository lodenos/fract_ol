#ifndef COLOR_H
#define COLOR_H

#include <math.h>
#include "type.h"
#include "vector.h"

typedef struct rgb8_s  rgb8_t;
typedef struct rgb16_s rgb16_t;

typedef struct rgba8_s  rgba8_t;
typedef struct rgba16_s rgba16_t;

typedef struct hsl8_s  hsl8_t;
typedef struct hsl16_s hsl16_t;

typedef struct hsla8_s  hsla8_t;
typedef struct hsla16_s hsla16_t;

// Color Type - RGB

struct rgb8_s {
  union {
    struct {
      u8_t r;
      u8_t g;
      u8_t b;
    };
    struct {
      u8_t red;
      u8_t green;
      u8_t blue;
    };
  };
};

struct rgb16_s {
  union {
    struct {
      u16_t r;
      u16_t g;
      u16_t b;
    };
    struct {
      u16_t red;
      u16_t green;
      u16_t blue;
    };
  };
};

struct rgba8_s {
  union {
    struct {
      u8_t r;
      u8_t g;
      u8_t b;
      u8_t a;
    };
    struct {
      u8_t red;
      u8_t green;
      u8_t blue;
      u8_t alpha;
    };
  };
};

struct rgba16_s {
  union {
    struct {
      u16_t r;
      u16_t g;
      u16_t b;
      u16_t a;
    };
    struct {
      u16_t red;
      u16_t green;
      u16_t blue;
      u16_t alpha;
    };
  };
};

// Color Type - HSL

// INFO: HSL  8 bits
// hue       : range: 0 to 255 is scale form 0 to 360 degree
// saturation: range: 0 to 255 is scale form 0 to 1
// lightness : range: 0 to 255 is scale form 0 to 1

// INFO: HSL 16 bits
// hue       : range: 0 to 65535 is scale form 0 to 360 degree
// saturation: range: 0 to 65535 is scale form 0 to 1
// lightness : range: 0 to 65535 is scale form 0 to 1

struct hsl8_s {
  union {
    struct {
      u8_t h;
      u8_t s;
      u8_t l;
    };
    struct {
      u8_t hue;
      u8_t saturation;
      u8_t lightness;
    };
  };
};

struct hsl16_s {
  union {
    struct {
      u16_t h;
      u16_t s;
      u16_t l;
    };
    struct {
      u16_t hue;
      u16_t saturation;
      u16_t lightness;
    };
  };
};

struct hsla8_s {
  union {
    struct {
      u8_t h;
      u8_t s;
      u8_t l;
      u8_t a;
    };
    struct {
      u8_t hue;
      u8_t saturation;
      u8_t lightness;
      u8_t alpha;
    };
  };
};

struct hsla16_s {
  union {
    struct {
      u16_t h;
      u16_t s;
      u16_t l;
      u16_t a;
    };
    struct {
      u16_t hue;
      u16_t saturation;
      u16_t lightness;
      u16_t alpha;
    };
  };
};

static __inline__ rgb8_t hsl8_to_rgb8(hsl8_t hsl) {
  // Scale
  const f64_t h = (360.0 * hsl.h) / 255.0;
  const f64_t s = hsl.s / 255.0;
  const f64_t l = hsl.l / 255.0;

  const f64_t c = (1.0 - fabs(2.0 * l - 1.0)) * s;
  const f64_t x = c * (1.0 - fabs(fmod(h / 60.0, 2.0) - 1.0));
  const f64_t m = l - c / 2.0;

  v3_f64_t color;

  if (h < 60.0)
    color = (v3_f64_t){ .a = c, .b = x, .c = 0 };
  else if (h < 120.0)
    color = (v3_f64_t){ .a = x, .b = c, .c = 0 };
  else if (h < 180.0)
    color = (v3_f64_t){ .a = 0, .b = c, .c = x };
  else if (h < 240.0)
    color = (v3_f64_t){ .a = 0, .b = x, .c = c };
  else if (h < 300.0)
    color = (v3_f64_t){ .a = x, .b = 0, .c = c };
  else
    color = (v3_f64_t){ .a = c, .b = 0, .c = x };

  return (rgb8_t){
    .r = (u8_t)((color.x + m) * 255.0),
    .g = (u8_t)((color.y + m) * 255.0),
    .b = (u8_t)((color.z + m) * 255.0)
  };
}

static __inline__ rgba8_t hsla8_to_rgba8(hsla8_t hsla) {
  // Scale
  const f64_t h = (360.0 * hsla.h) / 255.0;
  const f64_t s = hsla.s / 255.0;
  const f64_t l = hsla.l / 255.0;

  const f64_t c = (1.0 - fabs(2.0 * l - 1.0)) * s;
  const f64_t x = c * (1.0 - fabs(fmod(h / 60.0, 2.0) - 1.0));
  const f64_t m = l - c / 2.0;

  v4_f64_t color;

  if (h < 60.0)
    color = (v4_f64_t){ .a = c, .b = x, .c = 0 };
  else if (h < 120.0)
    color = (v4_f64_t){ .a = x, .b = c, .c = 0 };
  else if (h < 180.0)
    color = (v4_f64_t){ .a = 0, .b = c, .c = x };
  else if (h < 240.0)
    color = (v4_f64_t){ .a = 0, .b = x, .c = c };
  else if (h < 300.0)
    color = (v4_f64_t){ .a = x, .b = 0, .c = c };
  else
    color = (v4_f64_t){ .a = c, .b = 0, .c = x };

  return (rgba8_t){
    .r = (u8_t)((color.x + m) * 255.0),
    .g = (u8_t)((color.y + m) * 255.0),
    .b = (u8_t)((color.z + m) * 255.0),
    .a = 0 // TODO: think about the alpha implementation
  };
}

static __inline__ rgb16_t hsl16_to_rgb16(hsl16_t hsl) {
  // Scale
  const f64_t h = (360.0 * hsl.h) / 255.0;
  const f64_t s = hsl.s / 255.0;
  const f64_t l = hsl.l / 255.0;

  const f64_t c = (1.0 - fabs(2.0 * l - 1.0)) * s;
  const f64_t x = c * (1.0 - fabs(fmod(h / 60.0, 2.0) - 1.0));
  const f64_t m = l - c / 2.0;

  v3_f64_t color;

  if (h < 60.0)
    color = (v3_f64_t){ .a = c, .b = x, .c = 0 };
  else if (h < 120.0)
    color = (v3_f64_t){ .a = x, .b = c, .c = 0 };
  else if (h < 180.0)
    color = (v3_f64_t){ .a = 0, .b = c, .c = x };
  else if (h < 240.0)
    color = (v3_f64_t){ .a = 0, .b = x, .c = c };
  else if (h < 300.0)
    color = (v3_f64_t){ .a = x, .b = 0, .c = c };
  else
    color = (v3_f64_t){ .a = c, .b = 0, .c = x };

  return (rgb16_t){
    .r = (u16_t)((color.x + m) * 255.0),
    .g = (u16_t)((color.y + m) * 255.0),
    .b = (u16_t)((color.z + m) * 255.0)
  };
}

#endif
