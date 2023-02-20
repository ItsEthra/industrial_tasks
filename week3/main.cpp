#include <iostream>

#include "equation.h"
#include "rational.h"

using namespace std;

Rational add_rationals(Rational lhs, Rational rhs) {
	return Rational(lhs.numerator + rhs.numerator, lhs.denominator + rhs.denominator);
}

int main() {
	Equation eq(1, -7, 10);
	cout << eq.solve() << endl;
	Equation other = eq + Equation(0, -6, 32);
	cout << other.solve() << endl;

	Rational a(1, 2);
	
	return 0;
}
