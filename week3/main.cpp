#include <iostream>

#include "equation.h"
#include "rational.h"

using namespace std;

Rational sub_rationals(Rational lhs, Rational rhs) {
  Rational self = lhs;
  if (self.denominator != rhs.denominator) {
    self.numerator *= rhs.denominator;
    self.denominator *= rhs.denominator;

    rhs.numerator *= lhs.denominator;
    rhs.denominator *= lhs.denominator;
  }

  Rational ratio = Rational();
  ratio.set(self.numerator - rhs.numerator, self.denominator);

  return ratio;
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
		nums[i].show();
	}

	Rational sum = nums[0];
	for (int i = 1; i < n; ++i) {
		sum = sum + nums[i];
	}
	cout << "Sum: ";
	sum.show();

	cout << "Sub nums[0] - nums[1]: ";
	(nums[0] - nums[1]).show();

	cout << "nums[0]++";
	Rational copy = nums[0];
	copy++;
	copy.show();

	cout << "nums[0] ==, > nums[1]: ";
	cout << (nums[0] == nums[1]) << " " << (nums[0] > nums[1]) << endl;

	delete[] nums;
	return 0;
}
