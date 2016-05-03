#ifndef DRZEWO_CZERWONO_CZARNE_HH
#define DRZEWO_CZERWONO_CZARNE_HH
#include <iostream>
#include "IDrzewo_Czerwono_Czarne.hh"

using namespace std;

class Drzewo:public IDrzewo_czerwono_czarne
{
private:

    Wezel* korzen;
    virtual void obroc_w_lewo(Wezel *x);
    virtual void obroc_w_prawo(Wezel *x);

public:
    Drzewo()
    {
        korzen=NULL;
    }
 /*   ~Drzewo()
    {
        usun(korzen);
    }*/
    virtual void wstaw(int x);
    virtual void wypisz(Wezel *x);
    virtual void wyswietl();
    virtual int znajdz(int x);
  //  virtual void usun(Wezel *x);

};

#endif
