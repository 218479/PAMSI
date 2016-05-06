#include "Graf.hh"

void Graf::DodajWierzcholek(int x)
{
    Liczba_Wierzcholkow+=x;
    Lista *tmp=new Lista[Liczba_Wierzcholkow];

    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        tmp[i]=Wierzcholki[i];
    }

    delete [] Wierzcholki ;
    Wierzcholki=new Lista[Liczba_Wierzcholkow];

    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        Wierzcholki[i]=tmp[i];
    }

    delete [] tmp;
}
void Graf::ZrobPolaczenie(int pierwszy, int drugi)
{
    if(pierwszy>Liczba_Wierzcholkow||drugi>Liczba_Wierzcholkow)
    {
        cout<<"Podane wierzcholki nie naleza do grafu!"<<endl;
        return;
    }
    else
    {
        Wierzcholki[pierwszy].dodaj(drugi,Wierzcholki[pierwszy].get_size());
        Wierzcholki[drugi].dodaj(pierwszy,Wierzcholki[drugi].get_size());
    }
}
bool Graf::CzyPolaczone(int pierwszy, int drugi)
{
    if(pierwszy>Liczba_Wierzcholkow||drugi>Liczba_Wierzcholkow)
    {
        cout<<"Podane wierzcholki nie naleza do grafu!"<<endl;
        return false;
    }
    else
    {
        if(Wierzcholki[pierwszy].przeszukaj(drugi)==drugi)
        {
            cout<<"SA POLACZONE!"<<endl;
            return true;
        }
        else
        {
            cout<<"NIE SA POLACZONE!"<<endl;
            return false;
        }
    }
}
void Graf::GetSasiadow(int x)
{
    for(int i=0; i<Wierzcholki[x].get_size(); i++)
    {

    }

}

void Graf::DFS_odwiedzaj(int x)
{
    odwiedzone[x]=true;
    int a=0;
    cout<<"ODWIEDZONO "<<x<<" ";
    for(int i=0; i<Wierzcholki[x].get_size(); i++)
    {
        a=Wierzcholki[x].get(i);
        if(odwiedzone[a]==false)
        {
            DFS_odwiedzaj(a);
        }
    }

}
void Graf::DFS()
{
    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        odwiedzone[i]=false;
    }
    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        if(odwiedzone[i]==false)
        {
            DFS_odwiedzaj(i);
        }
    }

}

void Graf::BFS(int x)
{
    Kolejka nowa;
    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        odwiedzone[i]=false;
    }
    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        nowa.push(i);
    }
    while(nowa.Rozmiar()!=0)
    {
        x=nowa.pop();

        cout<<"ODWIEDZONO "<<x<<" ";
     //   int a;
        for(int i=0; i<Wierzcholki[x].get_size(); i++)
        {
            if(odwiedzone[x]==false)
            {
                nowa.push(x);
            }
        }
        odwiedzone[x]=true;
    }
}
