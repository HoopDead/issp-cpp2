#include <iostream>
#include <vector>

using namespace std;

void changeToZeros(vector <double> vector)
{
    if(!vector.empty())
    {
        fill(vector.begin(), vector.end(), 0);
    }
    for(auto i : vector)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<double> v = {7.5, 5.5, 16, 8};
    changeToZeros(v);
    return 0;
}