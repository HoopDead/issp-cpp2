#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    const Complex ii(0, 1);
    Complex a[3];
    a[0] = Complex(1, 1);
    a[1] = a[0] + ii;
    a[2] = a[1];
    a[2] += ii;

    Complex d = a[1] + a[2];
    d += a[0];

    cout << a[0];
    for (int i = 1; i < 3; i++)
    {
        cout << " + " << a[i];
    }
    cout << " = " << d << "\n";
    cout << "jednostka urojona = " << ii.real() << " + " << ii.imag() << "i\n";
  return 0;
}