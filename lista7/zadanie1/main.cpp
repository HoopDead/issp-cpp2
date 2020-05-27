#include <iostream>
#include <sstream>
#include <typeinfo>


using namespace std;

auto char_to_int(char *in) {
    int out;
    stringstream str(in);
    str >> out;
    return out;
}

int main() {
    char znak[] = "10";
    cout << char_to_int(znak) << "\n";
    cout << typeid(char_to_int(znak)).name() << "\n";
}