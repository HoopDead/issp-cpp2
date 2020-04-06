#include <iostream>
#include "Samochod.h"

using namespace std;

int main()
{
    //Błędem w klasie Samochod.h było to, że argument _sruby(4*_kola) dzialal blednie, powinno byc _sruby(4*n)
    Samochod s4 (4);
    return 0;
}