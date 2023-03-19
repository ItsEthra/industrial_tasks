#pragma once

#include "cone.h"

class Frustum : public Cone {
	float cutoff;

public:
  inline Frustum(float cutoff)
		: Cone(), cutoff(cutoff) {}
  inline Frustum(float radius, float height, float cutoff)
		: Cone(radius, height), cutoff(cutoff) {}
  inline Frustum(float cx, float cy, float cz, float radius, float height, float cutoff) {
		this->set(cx, cy, cz, radius, height, cutoff);
  }

	void set(float cx, float cy, float cz, float radius, float height, float cutoff);
	void print();

	float area();
	float volume();
};
