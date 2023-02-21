#include <iostream>

#include "triangle.h"
#include "circle.h"
#include "figure.h"

using namespace std;

int main() {
	circle_test();

	Triangle tris[3];
	for (int i = 0; i < 3; i++) {
		double a, b, c;
		cin >> a >> b >> c;

		tris[i].set(a, b, c);
		if (!tris[i].exists())
			cout << "Triangle does not exist" << endl;
		else {
			cout << "Perimeter: " << tris[i].perimeter() << " Area: " << tris[i].area() << endl;
		}
	}

	Circle circles[3];
	for (int i = 0; i < 3; ++i) {
		double r, cx, cy;
		cin >> r >> cx >> cy;

		circles[i].set(r, cx, cy);
	}

	cout << "circles[0] overlaps with circles[1]: " <<
		circles[0].overlaps_with(circles[1]) << endl;

	float a, b, c;
	cin >> a >> b >> c;

	for (int i = 0; i < 3; ++i) {
		cout << "Triangle " << i << " around: "<< circles[i].triangle_around(a, b, c) << endl;
		cout << "Triangle " << i << " in: "<< circles[i].triangle_in(a, b, c) << endl;
	}

	Figure figures[3];
	for (int i = 0; i < 3; ++i) {
		float x1, x2, x3, x4,
					y1, y2, y3, y4;
		cin >> x1 >> x2 >> x3 >> x4
				>> y1 >> y2 >> y3 >> y4;

		figures[i] = Figure(x1, y1, x2, y2, x3, y3, x4, y4);
		cout << "Right: " << figures[i].is_right() << endl;
		cout << "Square: " << figures[i].is_rhomb() << endl;
		cout << "Rhomb: " << figures[i].is_square() << endl;
		cout << "In circle: " << figures[i].is_in_circle() << endl;
		cout << "Out circle: " << figures[i].is_out_circle() << endl;
	}
	
	return 0;
}
