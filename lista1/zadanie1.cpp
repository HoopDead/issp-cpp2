#include <iostream>

using namespace std;

//Argument wejściowy: n - ilość liczb
//Argument wyjściowy: Wynik silni
void silnia(int n)
{
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        ans *= i;
        cout << i << ": "<< ans << endl;
    }
}
//Błąd w postaci błędnych wyników dla dużych liczb wiąże się z wyjściem poza zakres liczbowy typu int - <-2147483648 to 2147483647>

int main()
{
    silnia(40);
    return 0;
}