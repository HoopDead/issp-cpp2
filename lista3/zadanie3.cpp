#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    //NEW_DELETE
    auto t_wskazniki1 = chrono::high_resolution_clock::now();
    for(unsigned n = 1; n <= 4000000; ++n)
    {
        int *p = new int[n];
        delete [] p;
    }
    auto t_wskazniki2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t_wskazniki2 - t_wskazniki1).count();
    
    //DODAWANIE
    int x = 0;
    auto t_dodawanie1 = chrono::high_resolution_clock::now();
    for (unsigned n = 1; n < 4000000; ++n)
    {
        x = x + 50;
    }
    auto t_dodawanie2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(t_dodawanie2 - t_dodawanie1).count();
    cout << "Czas new/delete " << duration << "\n";
    cout << "Czas dodawanie " << duration2 << "\n";
    //Program do dodawania jest dużo szybszy, niż ten z new/delete.
    return 0;
}