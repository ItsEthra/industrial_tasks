class Equation {
private:
  double a, b, c;

  double D;
public:
  Equation(double a, double b, double c);
  void set(double a, double b, double c);

  // find_x
  double solve();

  // find_y
  double compute(double x);

  Equation operator+(Equation rhs);
};
