#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    /*
        Wynik działania programu, jest zależny od kompilatora -
        W przypadku, kiedy kompilator zapisze sobie zmienną tmp nad zmienna haslo, wtedy
        kiedy wpiszemy haslo dluzsze od rozmiaru - w tym przypadku 8, sama zmienna haslo
        zostaje nadpisana i w takim przypadku, nawet wpisanie poprawnego hasla nie pozwoli nam
        zalogowac sie do systemu.

        W przypadku, kiedy zmienna tmp jest niżej i wpiszemy więcej od rozmiaru,
        wtedy wrzuca nas do systemu, ale otrzymuje błąd:
        0witaj w systemie 
        *** stack smashing detected ***: <unknown> terminated
        Aborted (core dumped)
    */
    char haslo[8];
    strcpy(haslo,"1234");
    for(;;)
    {
        std::cout << "podaj haslo: ";
        char tmp[8];
        std::cin >> tmp;
        cout << strcmp(tmp, haslo);
        if(strcmp(tmp,haslo) == 0)
            break;
        std::cout << "wpisales zle haslo! \n";
    }
    std::cout << "witaj w systemie \n";
    return 0;
}
