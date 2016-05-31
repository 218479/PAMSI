#ifndef GRAF_HH
#define GRAF_HH
#include "Lista.hh"
#include "Kolejka.hh"
#include "IGraf.hh"
#include <queue>
#include <climits>

using namespace std;

struct Branch
{
    Lista lista;
    int wierzcholek;
    int koszt;
    Branch(Lista x, int y, int z)
    {
        lista=x;
        wierzcholek=y;
        koszt=z;
    }
};


class Graf: public IGraf
{
private:

    Lista *Wierzcholki;
    int Liczba_Wierzcholkow;
    bool *odwiedzone;
    int **waga_krawedzi;
public:
    Graf(int x)
    {
        Liczba_Wierzcholkow=x;
        Wierzcholki=new Lista[Liczba_Wierzcholkow];
        odwiedzone=new bool[Liczba_Wierzcholkow];
        waga_krawedzi=new int* [x];
        for(int i=0;i<x;i++)
        {
            waga_krawedzi[i]=new int [x];
        }
        for(int i=0;i<Liczba_Wierzcholkow;i++)
        {
            odwiedzone[i]=false;
        }


    }
    ~Graf()
    {
        for(int i=0;i<Liczba_Wierzcholkow;i++)
        {
            delete [] waga_krawedzi[i];
        }
        delete [] waga_krawedzi;
        delete [] odwiedzone;
        delete [] Wierzcholki;
    }
    virtual void DodajWierzcholek(int x);
    virtual void ZrobPolaczenie(int pierwszy, int drugi, int waga);
    virtual bool CzyPolaczone(int pierwszy, int drugi);
    virtual int GetWagaKrawedzi(int pierwszy, int drugi);
    virtual Lista GetSasiadow(int x);
    virtual void DFS_odwiedzaj(int x);
    virtual void DFS();
    void BFS();
    int BranchAndBound(int szukany);
    int BranchAndBoundWithExtendedList(int szukany);
};

#endif // GRAF_HH
