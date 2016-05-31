#ifndef ILISTA_HH
#define ILISTA_HH
#include <iostream>
#include <cstdlib>

using namespace std;

struct Element
{
    int dana;
    Element *nastepny;

    Element(int x)
    {
        dana=x;
        nastepny=NULL;
    }
};

class ILista
{
private:

public:
    virtual void dodaj(int x,int nr)=0;
    virtual void usun(int pozycja)=0;
    virtual int get(int nr)=0;
    virtual int get_size()=0;
    virtual bool przeszukaj(int a)=0;
};

#endif // LISTA_HH
