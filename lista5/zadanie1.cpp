#include <iostream>
#include "stos_zad1.h"

using namespace std;

int main() {
    Stos stack;
    for(int i = 0; i < 25; i++) { stack.push(i); }
    while(!stack.empty()) { stack.pop(); }
    cout << stack.top();
    return 0;
}