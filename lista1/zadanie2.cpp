#include <iostream>
#include <cmath>

using namespace std;


//Porównanie dwóch liczb
//Argument wejściowy - dwie dowolne liczby typu double do porównania
//Argument wyjściowy - wynik porównania dwóch liczb
double compare(double a, double b)
{
    cout << "Wartość porównania: " << b - a << endl;
}

//Podpunkt A
//Argument wejściowy - ilość liczb do obliczenia
//Argument wyjściowy - wynik sumy liczb
double subsectionA(int n) {
    double ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += 4 * ((pow(-1, i+1)) / (2*i - 1));
    }
    return ans;
}

//Podpunkt B
//Argument wejściowy - ilość liczb do obliczenia
//Argument wyjściowy - wynik sumy iloczynu 
double subsectionB(int n) {
    double ans = 1;
    for(int i = 1; i <= n; i++)
    {
        ans *= ((4 * pow(i, 2)) / ((4*pow(i, 2)) - 1));
    }
    return 2 * ans;
}


//Podpunkt C
//Argument wejściowy - ilość liczb n
//Argument wyjściowy - wynik sumy liczb 
double subsectionC(int n) {
    double ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += 1 / pow(2*i - 1, 2);
    }
    return sqrt(8 * ans);
}

int main()
{
    const int n = 1000000;
    cout << "Wartosc podpunktu A: " << subsectionA(n) << endl;
    compare(subsectionA(n), M_PI);
    cout << "Wartosc podpunktu B: " << subsectionB(n) << endl;
    compare(subsectionB(n), M_PI);
    cout << "Wartosc podpunktu C: " << subsectionC(n) << endl;
    compare(subsectionC(n), M_PI);
    return 0;
}