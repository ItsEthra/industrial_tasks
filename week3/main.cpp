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

	int n = 0;
	cin >> n;

	Rational* nums = new Rational[n];
	for (int i = 0; i < n; ++i) {
		int n, d;
		cin >> n >> d;
		nums[i].set(n, d); 
	}

	Rational sum = nums[0];
	for (int i = 1; i < n; ++i) {
		sum = sum + nums[i];
	}
	cout << "Sum: ";
	sum.show();

	return 0;
}
