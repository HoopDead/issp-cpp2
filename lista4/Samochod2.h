#include <iostream>
class Samochod
{

  private:

    int _sruby;
    int _kola;

  public:
    Samochod(int n)
    {
      _kola = n;
      _sruby = 4*_kola;
      std::cout << "Samochód z " << _kola << " kolami i " << _sruby << " srubami \n";
    }
};