class Rational {
private:
  int numerator, denominator;


public:
  friend Rational add_rationals(Rational lhs, Rational rhs);

  Rational(int numerator, int denominator);
  Rational();

  void set(int numerator, int denominator);
  void show();

  Rational operator+(Rational rhs);
  inline Rational operator-(Rational rhs) {
    return add_rationals(*this, rhs);
  }

  Rational operator++();
  bool operator>(Rational rhs);
  void operator=(Rational rhs);
};