#ifndef IGRAF_HH
#define IGRAF_HH
#include "Lista.hh"


class IGraf
{
private:

public:
    virtual void DodajWierzcholek(int x)=0;
    virtual void ZrobPolaczenie(int pierwszy, int drugi, int waga)=0;
    virtual bool CzyPolaczone(int pierwszy, int drugi)=0;
    virtual Lista GetSasiadow(int x)=0;
    virtual int GetWagaKrawedzi(int pierwszy, int drugi)=0;
//    virtual void DFS_odwiedzaj(int x)=0;
//    virtual void DFS()=0;
//   virtual void BFS()=0;
};


#endif // IGRAF_HH
