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

void circle_test();