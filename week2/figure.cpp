#include <iostream>

#include "figure.h"

using namespace std;

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
  return false;  
}

bool Figure::is_square() {
  return false;  
}

bool Figure::is_rhomb() {
  return false;  
}

bool Figure::is_in_circle() {
  return false;  
}

bool Figure::is_out_circle() {
  return false;  
}
