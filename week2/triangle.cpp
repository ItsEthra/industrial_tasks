#include <math.h>
#include <iostream>
#include "triangle.h"

bool Triangle::exists() {
	if (a + b <= c || a + c <= b || b + c <= a) return false;
	return true;
}

void Triangle::set(double a, double b, double c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

void Triangle::show() {
	std::cout << "A: " << this->a << " B: " << this->b << " C: " << this->c << std::endl;
}

double Triangle::perimeter() {
	return a + b + c;
}

double Triangle::area() {
	double halfp = this->perimeter() / 2;	
	double a = halfp - a, b = halfp - b, c = halfp - c;
	return sqrt(halfp * a * b * c);
}

