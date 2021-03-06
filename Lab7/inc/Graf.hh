#ifndef GRAF_HH
#define GRAF_HH
#include "Lista.hh"
#include "Kolejka.hh"
#include "IGraf.hh"
using namespace std;

class Graf: public IGraf
{
private:

    Lista *Wierzcholki;
    int Liczba_Wierzcholkow;
    bool *odwiedzone;

public:
    Graf(int x)
    {
        Liczba_Wierzcholkow=x;
        Wierzcholki=new Lista[Liczba_Wierzcholkow];
        odwiedzone=new bool[Liczba_Wierzcholkow];
        for(int i=0;i<Liczba_Wierzcholkow;i++)
        {
            odwiedzone[i]=false;
        }
    }
    virtual void DodajWierzcholek(int x);
    virtual void ZrobPolaczenie(int pierwszy, int drugi);
    virtual bool CzyPolaczone(int pierwszy, int drugi);
    virtual Lista GetSasiadow(int x);
    virtual void DFS_odwiedzaj(int x);
    virtual void DFS();
    void BFS();
};

#endif // GRAF_HH
