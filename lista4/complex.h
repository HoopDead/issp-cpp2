using namespace std;

class Complex
{
public:
    float _real;
    float _imag;

    Complex (float real=0.0, float imag=0.0): _real(real), _imag(imag) {}
    float real() const { return _real;}
    float imag() const { return _imag;}

    Complex operator+=(Complex const& a)
    {
        _real += a._real;
        _imag += a._imag;
        return *this;
    }

    Complex operator-=(Complex const& a)
    {
        _real -= a._real;
        _imag -= a._imag;
        return *this;
    }

    Complex operator*=(Complex const& a)
    {
        float temp = _real;
        _real = a._real*_real-a._imag*_imag;
        _imag = a._real*_imag+temp*a._imag;
        return *this;
    }

    Complex operator/=(Complex const& a)
    {
        float temp = _real;
        _real = a._real/_real-a._imag/_imag;
        _imag = a._real/_imag+temp/a._imag;
        return *this;
    }

    friend ostream& operator<<(ostream &out, Complex const& a)
    {
        out << "(" << a._real << "," << a._imag << ")";
        return out;
    }

};

Complex operator+(Complex const& a, Complex const& b)
{
    Complex c;
    c._real = a._real+b._real;
    c._imag = a._imag+b._imag;
    return c;
}

Complex operator-(Complex const& a, Complex const& b)
{
    Complex c;
    c._real = a._real-b._real;
    c._imag = a._imag+b._imag;
    return c;
}

Complex operator*(Complex const& a, Complex const& b)
{
    Complex c;
    c._real = a._real*b._real-a._imag*b._imag;
    c._imag = a._real*b._imag+b._real*a._imag;
    return c;
}

Complex operator/(Complex const& a, Complex const& b)
{
    Complex c;
    c._real = a._real/b._real-a._imag/b._imag;
    c._imag = a._real/b._imag+b._real/a._imag;
    return c;
}