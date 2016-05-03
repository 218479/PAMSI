#ifndef IDRZEWO_CZERWONO_CZARNE_HH
#define IDRZEWO_CZERWONO_CZARNE_HH
#include <iostream>
using namespace std;
struct Wezel
{
    int wartosc;
    int kolor;        //0-kolor czarny, 1-kolor czerwony
    Wezel* lewy;
    Wezel* prawy;
    Wezel* rodzic;
    Wezel(int x)
    {
        wartosc=x;
        lewy=NULL;
        prawy=NULL;
        rodzic=NULL;
    }

};
class IDrzewo_czerwono_czarne
{
private:
    virtual void obroc_w_lewo(Wezel *x)=0;
    virtual void obroc_w_prawo(Wezel *x)=0;
public:
    virtual void wstaw(int x)=0;
    virtual void wypisz(Wezel *x)=0;
    virtual void wyswietl()=0;
    virtual int znajdz(int x)=0;
 //   virtual void usun(Wezel *x)=0;
};

#endif // IDRZEWO_CZERWONO_CZARNE_HH
