#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

static vector<int> fib_static = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};


int fibo1(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibo1(n-1) + fibo1(n-2);
}

int fibo2(int n)
{
    int fn = round(((1/sqrt(5)) * ( pow((2/( sqrt(5)-1 )),n) - pow((-2/( sqrt(5)+1 )),n))));
    return fn;
}

int fibo3(int n)
{
    const int size = 48;
    static bool first = true;
    static vector<int> fn(size);
    if (first)
    {
        first =  false;
        for(int i = 0; i < size; i++)
        {
            fn[i] = round((1 / sqrt(5)) * (pow((2 / (sqrt(5) - 1)), i) - pow((-2 / (sqrt(5) + 1)), i)));
        }
    }
    return fn[n];
}


int main()
{
    //PODPUNKT A
    cout << fibo1(5) << "\n";
    //PODPUNKT B
    cout << fibo2(5) << "\n";
    //PODPUNKT C
    cout << fibo3(5) << "\n";
    for(int i = 0; i < 10; i++)
    {
        cout << "======" << i << "======" << "\n";
        cout << fibo1(i) << "\n";
        cout << fibo2(i) << "\n";
        cout << fibo3(i) << "\n";
    }
    //PODPUNKT D
	// auto t1 = chrono::high_resolution_clock::now();
	// for (int i = 1; i <= 48; i++) {
	// 	cout << fibo1(i) << " ";
	// }
	// cout << endl;
	// auto t2 = chrono::high_resolution_clock::now();
	// auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	// cout << "Czas fibo1(): " << duration;
    //Czas fibo1(): 80458028 mircoseconds

	// auto t1 = chrono::high_resolution_clock::now();
	// for (int i = 1; i <= 48; i++) {
	// 	cout << fibo2(i) << " ";
	// }
	// cout << endl;
	// auto t2 = chrono::high_resolution_clock::now();
	// auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	// cout << "Czas fibo2(): " << duration;
    //Czas fibo2(): 71 microseconds



    // auto t1 = chrono::high_resolution_clock::now();
	// for (int i = 1; i < 48; i++) {
	// 	cout << fibo3(i) << " ";
	// }
	// cout << endl;
	// auto t2 = schrono::high_resolution_clock::now();
	// auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	// cout << "Czas fibo3(): " << duration;
    //Czas fibo3(): 47 microseconds
    return 0;
}