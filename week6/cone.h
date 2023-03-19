#pragma once

class Cone {
protected:
  float cx, cy, cz, radius, height;

public:
  inline Cone()
    : cx(0), cy(0), cz(0), radius(1), height(1) {}
  inline Cone(float radius, float height) 
    : cx(0), cy(0), cz(0), radius(radius), height(height) {}
  inline Cone(float cx, float cy, float cz, float radius, float height) {
    this->set(cx, cy, cz, radius, height);
  }

  void set(float cx, float cy, float cz, float radius, float height);
  void print();

  float area();
  float lateral_surface();
  float volume();
};
