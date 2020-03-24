#include <iostream>
#include <cmath>

using namespace std;


void archimedes_pi_1(double n)
{
    double ti = n;
    for(int i = 0; i <= 30; i++)
    {
        ti = (sqrt(pow(ti, 2) + 1) - 1) / ti;
        double pi = 6 * pow(2, i) * ti;
        cout << i << ": " << pi * 2 << endl;
    }
}

void archimedes_pi_2(double n)
{
    double ti = n;
    for(int i = 0; i <= 30; i++)
    {
        ti = ti / (sqrt(pow(ti, 2) + 1) + 1);
        double pi = 6 * pow(2, i) * ti;
        cout << i << ": " << pi * 2 << endl;
    }
}

int main()
{
    const double t0 = 1/sqrt(3);
    //Dla zadanej funkcji błąd wzrasta
    archimedes_pi_1(t0);
    cout << "====================" << endl;
    //Dla zadanej funkcji błąd maleje
    archimedes_pi_2(t0);
    return 0;
}