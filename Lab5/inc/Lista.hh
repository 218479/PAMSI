#ifndef LISTA_HH
#define LISTA_HH
#include "ILista.hh"
#include "stoper.hh"

class Lista: public ILista
{
private:
    Element *poczatek;
    Element *koniec;
public:
    Lista()
    {
        poczatek=NULL;
        koniec=NULL;
    }
    virtual void dodaj(string x,int nr);
    virtual void usun(int pozycja);
    virtual string get(int nr);
    virtual int get_size();
    virtual void przeszukaj(string a);

};

#endif
