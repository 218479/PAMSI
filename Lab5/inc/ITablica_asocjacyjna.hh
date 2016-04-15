#ifndef ITABLICA_ASOCJACYJNA_HH
#define ITABLICA_ASOCJACYJNA_HH

#include "Lista.hh"

class ITablica_asocjacyjna:public Lista{
private:

public:
    virtual int znajdz()=0;
    virtual void wloz()=0;
    virtual void usun()=0;
};

#endif // ITABLICA_ASOCJACYJNA_HH
