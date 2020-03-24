#include <iostream>

unsigned silnia(unsigned n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * silnia(n-1);
    }
}

int main()
{
    for(int i = 0; i < 5; ++i)
    {
        std::cout << i << "! = " << silnia(i) << "\n";
    }
    silnia(-1);
    //Oczekiwany wynik dla wywłania powyższej funkcji to błąd, związany z przeciążeniem pamięci Segmetation fault (core dumped) - dzieje się tak dlatego, ponieważ zastosowaliśmy typ unsigned, który w swoim zakresie nie dopuszcza do użycia liczby ujemnej.
}