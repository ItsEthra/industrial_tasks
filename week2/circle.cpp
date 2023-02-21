#include <math.h>
#include <iostream>

#include "circle.h"
#include "triangle.h"

using namespace std;

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

bool Circle::overlaps_with(Circle& other) {
	float dx = other.cx - this->cx, dy = other.cy - this->cy;
	float dist = sqrt(dx * dx + dy * dy);

	return dist < other.radius + this->radius;
}

void circle_test() {
	Circle c1(2, 0, 0), c2(2, 0, 1);

#define TOF(expr) (expr ? "true" : "false")
	cout << "Does c1 instersects c2: " << TOF(c1.overlaps_with(c2)) << endl;

	Circle c3(1, 0, 2), c4(1, 0, -2);

	cout << "Does c3 instersects c4: " << TOF(c3.overlaps_with(c4)) << endl;
}
