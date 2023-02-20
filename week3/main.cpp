#include <iostream>

#include "equation.h"
#include "rational.h"

using namespace std;

int main() {
	Equation eq(1, -7, 10);
	cout << eq.solve() << endl;
	Equation other = eq + Equation(0, -6, 32);
	cout << other.solve() << endl;
	return 0;
}
