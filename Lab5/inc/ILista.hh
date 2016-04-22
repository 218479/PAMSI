#ifndef ILISTA_HH
#define ILISTA_HH
#include <iostream>
#include <cstdlib>

using namespace std;

struct Element
{
    string dana;
    Element *nastepny;

    Element(string x)
    {
        dana=x;
        nastepny=NULL;
    }
};

class ILista
{
private:

public:
    virtual void dodaj(string x,int nr)=0;
    virtual void usun(int pozycja)=0;
    virtual string get(int nr)=0;
    virtual int get_size()=0;
    virtual void przeszukaj(string a)=0;

};

#endif // LISTA_HH
