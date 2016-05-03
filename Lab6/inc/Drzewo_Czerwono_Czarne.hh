#ifndef DRZEWO_CZERWONO_CZARNE_HH
#define DRZEWO_CZERWONO_CZARNE_HH
#include <iostream>
#include "IDrzewo_Czerwono_Czarne.hh"

using namespace std;

class Drzewo:public IDrzewo_czerwono_czarne
{
private:

    Wezel lisc;
    Wezel* korzen;
    virtual void obroc_w_lewo(Wezel *x);
    virtual void obroc_w_prawo(Wezel *x);
    virtual void wypisz(Wezel *x);
public:
    Drzewo()
    {
        lisc.kolor=0;
        lisc.rodzic=&lisc;
        lisc.prawy=&lisc;
        lisc.lewy=&lisc;
        korzen=&lisc;
    }
    ~Drzewo()
    {
        usun(korzen);
    }
    virtual void wstaw(int x);
    virtual void wyswietl();
    virtual int znajdz(int x);
    virtual void usun(Wezel *x);
    void reset();

};

#endif
