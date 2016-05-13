#ifndef GRAF_HH
#define GRAF_HH
#include "Lista.hh"
#include "Kolejka.hh"

using namespace std;

class Graf
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
    void DodajWierzcholek(int x);
    void ZrobPolaczenie(int pierwszy, int drugi);
    bool CzyPolaczone(int pierwszy, int drugi);
    void GetSasiadow(int x);
    void DFS_odwiedzaj(int x);
    void DFS();
    void BFS(int x);
};

#endif // GRAF_HH
