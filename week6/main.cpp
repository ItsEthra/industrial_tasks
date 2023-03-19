#include <iostream>

#include "cone.h"

using namespace std;

int main() {
  Cone* cone = new Cone(5, 2);
  cone->print();

  Cone* array = new Cone[3];
  for (int i = 0; i < 3; ++i) {
    float cx, cy, cz, radius, height;
    cin >> cx >> cy >> cz >> radius >> height;
    array[i] = Cone(cx, cy, cz, radius, height);
    array[i].print();
  }

  return 0;
}