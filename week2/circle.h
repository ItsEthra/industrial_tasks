#include <iostream>

class Circle {
private:
	float radius;
	float cx, cy;

public:
	inline Circle(float radius, float cx, float cy) : radius(radius), cx(cx), cy(cy) {}

	void set(float radius, float cx, float cy);
	float square();

	bool triangle_around(float a, float b, float c);
	bool triangle_in(float a, float b, float c);
	bool check_circle(Circle& other);
};


static void circle_test() {
	Circle c1(2, 0, 0), c2(2, 0, 1);

#define TOF(expr) (expr ? "true" : "false")
	std::cout << "Does c1 instersects c2: " << TOF(c1.check_circle(c2)) << std::endl;

	Circle c3(1, 0, 2), c4(1, 0, -2);

	std::cout << "Does c3 instersects c4: " << TOF(c3.check_circle(c4)) << std::endl;
}