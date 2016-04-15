#ifndef ITABLICA_HASZUJACA_HH
#define ITABLICA_HASZUJACA_HH

#include "ITablica_asocjacyjna.hh"

#include <string.h>

class ITablica_haszujaca: public ITablica_asocjacyjna{
private:

public:
    virtual int znajdz(string klucz)=0;
    virtual void wloz(string klucz, int dana)=0;
    virtual void usun(string klucz, int dana)=0;
    virtual void haszuj()=0;

};
#endif // ITABLICA_HASZUJACA_HH
