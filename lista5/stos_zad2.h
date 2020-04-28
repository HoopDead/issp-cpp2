struct Ogniwo {
    Ogniwo(int n, Ogniwo* p): _dane(n), _p_nastepny(p) { }
    int _dane;
    Ogniwo* _p_nastepny;
};

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
        Stos& operator=(Stos const&); 
        friend std::ostream& operator <<(std::ostream& os, const Stos& obj);
    private:
        Ogniwo* _pSzczyt; 
        size_t _size; 
};

Stos::Stos(): _pSzczyt(0), _size(0) { }
Stos::Stos(const Stos &x): _size(x._size) { 
    _pSzczyt = new Ogniwo(x._pSzczyt->_dane,0);
    Ogniwo* begin = _pSzczyt;
    Ogniwo* temp = x._pSzczyt;
    while(temp->_p_nastepny != nullptr)
    {
        temp = temp->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(temp->_dane,_pSzczyt->_p_nastepny);
        _pSzczyt = _pSzczyt->_p_nastepny;

    }
    _pSzczyt->_p_nastepny = nullptr;
    _pSzczyt = begin;
}

Stos::~Stos() { while (!this->empty()) this->pop(); }

bool Stos::empty() const {return _pSzczyt == 0;}

int Stos::top() const { return _pSzczyt->_dane; }

int& Stos::top() { return _pSzczyt->_dane; }

size_t Stos::size() const { return _size; }

void Stos::push(int i) {
    _pSzczyt = new Ogniwo(i, _pSzczyt);
    _size++;
}

void Stos::pop() {
    Ogniwo* x = _pSzczyt;
    _pSzczyt = _pSzczyt -> _p_nastepny;
    _size--;
}
Stos& Stos::operator=(Stos const& x)
{
    if(this == &x) { return *this; }
    _pSzczyt = new Ogniwo(x._pSzczyt->_dane,0);
    Ogniwo* begin = _pSzczyt;
    Ogniwo* a = x._pSzczyt;
    while(a->_p_nastepny != nullptr)
    {
        a = a->_p_nastepny;
        _pSzczyt->_p_nastepny = new Ogniwo(a->_dane,_pSzczyt->_p_nastepny);
        _pSzczyt = _pSzczyt->_p_nastepny;
    }
    _pSzczyt = begin;
}