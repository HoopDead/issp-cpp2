#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex z1(1, 1);
    Complex z2(2, 2);
    Complex z3;
    cout << z1 + z2 << "\n";
    cout << z1 - z2 << "\n";
    cout << z1 * z2 << "\n";
    cout << z1 / z2 << "\n";
    cout << z1;
    cout << "\n";
    cin >> z3;
  return 0;
}