#ifndef TABLICA_HASZUJACA_HH
#define TABLICA_HASZUJACA_HH
#include "ITablica_haszujaca.hh"

class Tablica_haszujaca: public ITablica_haszujaca
{
private:
    Lista Tablica[10];
    int kod;
public:
    Tablica_haszujaca();
    virtual int znajdz(string klucz);
    virtual void wloz(string klucz, int dana);
    virtual void usun(string klucz, int dana);
    virtual int haszuj(string klucz)
    {
        for(int i=0; i<klucz.length(); i++)
        {
            kod=kod+(int)klucz[i];
        }
        kod=kod%10;
        return kod;
    }

    int operator [](string klucz)
    {
        return haszuj(klucz);
    }
};

#endif // TABLICA_HASZUJACA_HH
