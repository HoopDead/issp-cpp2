#include <iostream>
#include <vector>

using namespace std;

double operator*(vector<double> const v, vector<double> const w)
{
    if (v.size() != w.size())
    {
        cout << "Wektory nie są jednakowej długości!" << endl;
        return 0;
    }
    else
    {
        double wynik = 0;
        for(int i = 0; i < v.size(); i++)
        {
            wynik += v[i] * w[i];
        }
        return wynik;
    }
}

int main()
{
    vector<double> v = {2,1};
    vector<double> w = {2,1};
    cout << v * w << endl;
    return 0;
}