#ifndef TABLICA_HASZUJACA_HH
#define TABLICA_HASZUJACA_HH
#include "ITablica_haszujaca.hh"

class Tablica_haszujaca: public ITablica_haszujaca
{
private:
    Lista *Tablica;
    int rozmiar;
public:
    Tablica_haszujaca(int x)
    {
        rozmiar=x;
        Tablica=new Lista[rozmiar];
    }
    ~Tablica_haszujaca(){
    delete [] Tablica;
    }
    virtual void znajdz(string klucz);
    virtual void wloz(string klucz);
    virtual int haszuj(string klucz);

    void reset();
};

#endif // TABLICA_HASZUJACA_HH
