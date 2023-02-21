#include "rational.h"

#include <iostream>

using namespace std;

Rational::Rational(int numerator, int denominator) {
  this->set(numerator, denominator);
}

Rational::Rational() : numerator(0), denominator(0) {}

void Rational::set(int numerator, int denominator) {
  if (denominator == 0) {
    cout << "Denominator is 0" << endl;
    exit(1);
  }

  if (denominator % numerator == 0) {
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
  Rational self = *this;
  if (self.denominator != rhs.denominator) {
    self.numerator *= rhs.denominator;
    self.denominator *= rhs.denominator;

    rhs.numerator *= this->denominator;
    rhs.denominator *= this->denominator;
  }

  Rational ratio = Rational();
  ratio.set(self.numerator + rhs.numerator, self.denominator);

  return ratio;
}

void Rational::operator++(int) {
  this->set(this->numerator + 1, this->denominator);
}

bool Rational::operator==(Rational rhs) {
  return this->numerator == rhs.numerator && this->denominator == rhs.denominator;
}

bool Rational::operator>(Rational rhs) {
  double a = (double)this->numerator / (double)this->denominator,
         b = (double)rhs.numerator / (double)rhs.denominator;
  return a > b;
}

void Rational::operator=(Rational rhs) {
  this->set(rhs.numerator, rhs.denominator);
}
