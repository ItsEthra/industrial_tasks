#include <iostream>
#include <math.h>

#include "figure.h"

using namespace std;

#define EPSILON 0.001;
#define PI 3.1415


float angle(float x1, float y1, float x2, float y2) {
  return acos(x1 * x2 + y1 * y2);
}

float dist(float x1, float y1, float x2, float y2) {
	float dx = x2 - x1, dy = y2 - y1;
	return sqrt(dx * dx + dy * dy);
}

Figure::Figure(float x1, float y1, float x2, float y2,
      				 float x3, float y3, float x4, float y4)
	: x1(x1), y1(y1), x2(x2), y2(y2),
		x3(x3), y3(y3), x4(x4), y4(y4)
	{
		const float half = 1.0 / 2.0;
		this->area = half * ((x1 * y2 + x2 * y3 + x4 * y1) - 
			(x2 * y1 + x3 * y2 + x4 * y3 + x1 * y4));
    this->perimeter = dist(x1, y1, x2, y2) +
                      dist(x2, y2, x3, y3) +
                      dist(x3, y3, x4, y4) +
                      dist(x4, y4, x1, y1);
}
	
void Figure::show() {
  cout << "Area: " << this->area << " Perimeter: " << this->perimeter;
}

bool Figure::is_right() {
  bool first = abs(angle(x2 - x1, y2 - y1, x4 - x1, y4 - y1) - PI / 2.0) < EPSILON;
  bool second = abs(angle(x2 - x3, y2 - y3, x4 - x3, y4 - y3) - PI / 2.0) < EPSILON;

  return first && second;
}

bool Figure::is_square() {
  float a = dist(x1, y1, x2, y2);
  float b = dist(x2, y2, x3, y3);
  float c = dist(x3, y3, x4, y4);
  float d = dist(x4, y4, x1, y1);
  return is_right() && a == b && a == c && a == d;
}

bool Figure::is_rhomb() {
  float a = dist(x1, y1, x2, y2);
  float b = dist(x2, y2, x3, y3);
  float c = dist(x3, y3, x4, y4);
  float d = dist(x4, y4, x1, y1);
  return a == b && a == c && a == d;
}

bool Figure::is_in_circle() {
  float a = dist(x1, y1, x2, y2);
  float b = dist(x2, y2, x3, y3);
  float c = dist(x3, y3, x4, y4);
  float d = dist(x4, y4, x1, y1);

  return abs((a + c) - (c + d)) < EPSILON;
}

bool Figure::is_out_circle() {
  float a1 = angle(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
  float a2 = angle(x2 - x3, y2 - y3, x4 - x3, y4 - y3);

  return abs(a1 + a2 - PI) < EPSILON;
}
