#ifndef ITABLICA_ASOCJACYJNA_HH
#define ITABLICA_ASOCJACYJNA_HH

#include "Lista.hh"

class ITablica_asocjacyjna:public Lista{
private:

public:
    virtual void znajdz(string klucz)=0;
    virtual void wloz(string klucz)=0;
};

#endif // ITABLICA_ASOCJACYJNA_HH
