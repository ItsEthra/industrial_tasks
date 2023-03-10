class Figure {
private:
	float x1, x2, x3, x4,
				y1, y2, y3, y4;

	float area, perimeter;
public:
	Figure(float x1, float y1, float x2, float y2,
				 float x3, float y3, float x4, float y4);
	inline Figure() : x1(0), x2(0), x3(0), x4(0),
										y1(0), y2(0), y3(0), y4(0),
										area(0), perimeter(0) {}

	void show();
	bool is_right();
	bool is_square();
	bool is_rhomb();
	bool is_in_circle();
	bool is_out_circle();
};
