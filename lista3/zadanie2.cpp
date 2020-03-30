#include <iostream>

using namespace std;

double tablica_a[100];

double fillTablica_a() {
    for(int i = 0; i < 100; i++)
    {
        tablica_a[i] = i;
    }
}

double f(double* a, int b)
{
    return 1.0;
}

void g(int *a)
{
    *a = 5;
}

int main()
{
    //Przykład A
    fillTablica_a();
    double *wska = tablica_a;
    cout << wska << "\n";
    //Przykład B
    char *tablica_b[5][5];
    //Przykład C
    int x;
    char *const tablica_c = new char[x];
    //Przykład D
    vector<void*> t;
    //Przykład E
    vector<double>tablica_e[4]; 
    //Przykład F
    double (*f)(double*,int);
    //Przykłąd G
    int y = 0;
    g(&y);
    return 0;
}