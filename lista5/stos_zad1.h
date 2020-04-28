#include <cassert>


class Stos {
    public:
        Stos();
        Stos(Stos const&);
        ~Stos();

        void push(int i);
        void pop();
        int top() const;
        int& top();
        bool empty() const;
        size_t size() const;
        Stos& operator= (Stos const&);
    private:
        void _grow() {
            _capacity *= 2;
            int* p = new int[_capacity];
            for(size_t i = 0; i < _size; i++)
            {
                p[i] = _tab[i];
            }
            delete[] _tab;
            _tab = p;
        };
        void _shrink() {
            assert(_capacity >= 4);
            _capacity = _capacity / 2;
            int* p = new int[_capacity];
            for(size_t i = 0; i < _size; i++)
                p[i] = _tab[i];
            delete[] _tab;
            _tab = p;
        };
        size_t _capacity;
        size_t _size;
        int* _tab;
};

Stos::Stos(): _capacity(1), _size(0), _tab(new int[1]) {}

Stos::~Stos() { delete [] _tab; }

void Stos::push(int i) {
    if(_size == _capacity) { _grow(); }

    _tab[_size] = i;
    _size++;
}

void Stos::pop() {
    _size--;
    if(_capacity > 4 * _size) { _shrink(); std::cout << "Nie wolno wywolywac jesli capacity < 4"; }
}

int Stos::top() const { return _tab[_size-1]; }
int& Stos::top() { return _tab[_size-1]; }
bool Stos::empty() const {return _size == 0;}
size_t Stos::size() const {return _size;}