#include <iostream>
#include "triangle.h"
#include "circle.h"

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
		else
			cout << "Perimeter: " << tris[i].perimeter() << " Area: " << tris[i].area() << endl;			
	}

	return 0;
}
