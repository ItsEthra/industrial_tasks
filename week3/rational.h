class Rational {
private:
  int numerator, denominator;


public:
  friend Rational sub_rationals(Rational lhs, Rational rhs);

  Rational(int numerator, int denominator);
  Rational();

  void set(int numerator, int denominator);
  void show();

  Rational operator+(Rational rhs);
  inline Rational operator-(Rational rhs) {
    return sub_rationals(*this, rhs);
  }

  void operator++(int);
  bool operator==(Rational rhs);
  bool operator>(Rational rhs);
  void operator=(Rational rhs);
};