#include <iostream>
#include "dwa.h"
#include "trzy.h"
#include "cztery.h"

using namespace std;

class Raz : public Dwa {
    public:
    Raz() {
        Trzy trzy;
        cout << " destrukcji ";
    }
    ~Raz() {
        cout << " jest ";
    }
    Cztery _cztery;
};