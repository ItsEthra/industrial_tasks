#include <math.h>
#include <fmt/core.h>

#include "frustum.h"

void Frustum::set(float cx, float cy, float cz, float radius, float height, float cutoff) {
  Cone::set(cx, cy, cz, radius, height);
  this->cutoff = cutoff;
}

void Frustum::print() {
  fmt::print("Frustum {{\n\tCenter: ({}, {}, {}). Radius: {}. Height: {}. Cutoff: {}\n\tArea: {}. Volume: {}\n}}\n",
    cx, cy, cz,
    radius,
    height,
    cutoff,
    area(),
    volume()
  );
}

//  R     H
// --- = ---
//  r     h
//
// r = (R * h) / H;

float Frustum::area() {
  Cone top = Cone(radius * cutoff / height, cutoff);
  return Cone::area() - top.lateral_surface();
}

float Frustum::volume() {
  Cone top = Cone(radius * cutoff / height, cutoff);
  return Cone::volume() - top.volume();
}

