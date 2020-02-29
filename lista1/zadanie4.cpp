#include <iostream>


int main()
{
    const int N = 1000000;
    double suma = 0;
    for (double k = 1; k <= N; ++k)
    {
        suma += 1 / (k*k);
    }
    std::cout << suma << "\n";
}