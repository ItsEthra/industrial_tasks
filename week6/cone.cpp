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
  fmt::print("Cone {{\n\tCenter: ({}, {}, {}). Radius: {}. Height: {}.\n\tArea: {}. Volume: {}\n}}\n",
    cx, cy, cz,
    radius,
    height,
    area(),
    volume()
  );
}

#define PI 3.1415

float Cone::area() {
  return PI * radius * radius + lateral_surface();
}

float Cone::lateral_surface() {
  return PI * radius * sqrt(height * height + radius * radius);
}

float Cone::volume() {
  return PI * radius * radius * height / 3;
}
