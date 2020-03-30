#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    auto t1 = chrono::high_resolution_clock::now();
    for(unsigned n = 1; n <= 4000000; ++n)
    {
        auto start = chrono::high_resolution_clock::now();
        int *p = new int[n];
        delete [] p;
        auto end = chrono::high_resolution_clock::now();
    }
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "\n" << duration << "\n";
    return 0;
}