#include <math.h>

#include "circle.h"
#include "triangle.h"

void Circle::set(float radius, float cx, float cy) {
	this->radius = radius;
	this->cx = cx;
	this->cy = cy;	
}

float Circle::square() {
	return 3.1415 * this->radius * this->radius;
}

bool Circle::triangle_around(float a, float b, float c) {
	Triangle t;
	t.set(a, b, c);
	if (!t.exists()) return false;

	float s = (a + b + c) / 2;
	float expected_radius = sqrt((s - a) * (s - b) * (s - c) / s);
	return this->radius == expected_radius;
}

bool Circle::triangle_in(float a, float b, float c) {
	Triangle t;
	t.set(a, b, c);
	if (!t.exists()) return false;

	float s = (a + b + c) / 2;
	float expected_radius = (a * b * c) / (4 * sqrt(s * (s - a) * (s - b) * (s - c)));
	return this->radius == expected_radius;
}

bool Circle::check_circle(Circle& other) {
	float dx = other.cx - this->cx, dy = other.cy - this->cy;
	float dist = sqrt(dx * dx + dy * dy);

	return dist < other.radius + this->radius;
}
