#include <iostream>
#include <cmath>

using namespace std;

int i = 0;

double archimedes_pi_1(double n)
{
    while(i < 30)
    {
        double ans = (sqrt(pow(n, 2) + 1) - 1) / n;
        i++;
        cout << i << ": " << 6 * pow(2, i) * ans << endl;
        return archimedes_pi_1(ans);
    }
}

double archimedes_pi_2(double n)
{
    while(i < 30)
    {
        double ans = n/(sqrt(pow(n, 2) + 1) + 1);
        i++;
        cout << i << ": " << 6 * pow(2, i) * ans << endl;
        return archimedes_pi_2(ans);
    }
}

int main()
{
    const double t0 = 1/sqrt(3);
    archimedes_pi_1(t0);
    i = 0;
    archimedes_pi_2(t0);
    return 0;
}