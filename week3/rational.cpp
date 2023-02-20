#include "rational.h"

#include <iostream>

using namespace std;

Rational::Rational(int numerator, int denominator) {
  this->set(numerator, denominator);
}

void Rational::set(int numerator, int denominator) {
  if (denominator % numerator) {
    denominator /= numerator;
    numerator = 1;
  }

  this->numerator = numerator;
  this->denominator = denominator;
}

void Rational::show() {
  cout << this->numerator << '/' << this->denominator << endl;  
}

Rational Rational::operator+(Rational rhs) {
  return Rational(this->numerator + rhs.numerator, this->denominator + rhs.denominator);
}

Rational Rational::operator++() {
  Rational copy = *this;
  copy.set(copy.numerator + 1, copy.denominator);
  return copy;
}

bool Rational::operator>(Rational rhs) {
  double a = (double)this->numerator / (double)this->denominator,
         b = (double)rhs.numerator / (double)rhs.denominator;
  return a > b;
}

void Rational::operator=(Rational rhs) {
  this->set(rhs.numerator, rhs.denominator);
}
