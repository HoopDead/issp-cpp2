#include <iostream>
#include "stos_zad2.h"

using namespace std;

int main() {
    Stos stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    Stos stack2(stack);
    Stos stack3 = stack;
    cout << stack.top() << "\n";
    cout << stack2.top() << "\n";
    cout << stack3.top() << "\n";
    return 0;
}