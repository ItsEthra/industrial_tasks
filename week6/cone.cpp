#include <fmt/core.h>
#include <math.h>

#include "cone.h"

void Cone::set(float cx, float cy, float cz, float radius, float height)  {
  this->cx = cx;
  this->cy = cy;
  this->cz = cz;
  this->radius = radius;
  this->height = height;
}

void Cone::print() {
  fmt::print("Center: ({}, {}, {}). Radius: {}. Height: {}.\nArea: {}. Volume: {}\n",
    cx, cy, cz,
    radius,
    height,
    area(),
    volume()
  );
}

#define PI 3.1415

float Cone::area() {
  return PI * radius * (radius + sqrt(height * height + radius * radius));
}

float Cone::volume() {
  return PI * radius * radius * height / 3;
}
