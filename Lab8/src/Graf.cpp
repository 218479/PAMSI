#include "Graf.hh"


bool operator<(Branch a, Branch b)
{
    return a.koszt > b.koszt;
}

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
void Graf::ZrobPolaczenie(int pierwszy, int drugi, int waga)
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
    waga_krawedzi[pierwszy][drugi]=waga;
    waga_krawedzi[drugi][pierwszy]=waga;
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
        if(Wierzcholki[pierwszy].przeszukaj(drugi))
        {
            cout<<"SA POLACZONE, A WAGA TO: "<<waga_krawedzi[pierwszy][drugi]<<" A TAKZE "<<waga_krawedzi[drugi][pierwszy]<<endl;
            return true;
        }
        else
        {
            cout<<"NIE SA POLACZONE!"<<endl;
            return false;
        }
    }
}
Lista Graf::GetSasiadow(int x)
{
    return Wierzcholki[x];
}

void Graf::DFS_odwiedzaj(int x)
{
    odwiedzone[x]=true;
    int a=0;
    //cout<<"ODWIEDZONO "<<x<<" ";
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

void Graf::BFS()
{
    Lista nowa;
    int x=0;
    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        odwiedzone[i]=false;
    }
    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        nowa=GetSasiadow(i);
        while(nowa.get_size()!=0)
        {
            x=nowa.get(0);
            nowa.usun(0);
            if(odwiedzone[x]==false)
            {
                //    cout<<"Odwiedzono"<<x<<" ";
                odwiedzone[x]=true;
            }
        }
    }
}

int Graf::GetWagaKrawedzi(int pierwszy, int drugi)
{
    return waga_krawedzi[pierwszy][drugi];
}

int Graf::BranchAndBound(int szukany)
{
    priority_queue<Branch> Kolejka_;
    int wynik=INT_MAX;     //To zmienic pozniej
    Lista Nowa;
    Nowa.dodaj(0,0);
    Branch tmp(Nowa,0,0);
    Kolejka_.push(tmp);


    while(!Kolejka_.empty())
    {
        tmp=Kolejka_.top();
        Kolejka_.pop();

    //    cout << "Wierzcholek " << tmp.wierzcholek << " - " << tmp.koszt << endl;

    //    cout << "ma " << Wierzcholki[tmp.wierzcholek].get_size() << " sasiadow." << endl;

        for(int i=0; i<Wierzcholki[tmp.wierzcholek].get_size(); i++)
        {
            int D=Wierzcholki[tmp.wierzcholek].get(i);

     //       cout << "Sasiad wierzcholka " << tmp.wierzcholek << " " << D << endl;

            if(!tmp.lista.przeszukaj(D))
            {
       //         cout << "Nie ma wierzholka na liscie" << endl;
                if(D==szukany)
                {
                    if(tmp.koszt+waga_krawedzi[tmp.wierzcholek][D]<wynik)
                    {
                        wynik=tmp.koszt+waga_krawedzi[tmp.wierzcholek][D];
                    }
                }
                else
                {
                    if(tmp.koszt+waga_krawedzi[tmp.wierzcholek][D]<wynik)
                    {
                        Lista L=tmp.lista.kopiuj();
                        L.dodaj(D,L.get_size());
                        Branch B(L,D,tmp.koszt+waga_krawedzi[tmp.wierzcholek][D]);
                        Kolejka_.push(B);

                    }
                }
            }
        }
    }
    return wynik;
}
int Graf::BranchAndBoundWithExtendedList(int szukany)
{

    priority_queue<Branch> Kolejka_;
    int Tablica_wierzcholkow_odwiedzonych[Liczba_Wierzcholkow];
    for(int i=0; i<Liczba_Wierzcholkow; i++)
    {
        Tablica_wierzcholkow_odwiedzonych[i]=0;
    }
    int wynik=INT_MAX;     //To zmienic pozniej
    Lista Nowa;
    Nowa.dodaj(0,0);
    Branch tmp(Nowa,0,0);
    Kolejka_.push(tmp);


    while(!Kolejka_.empty())
    {
        tmp=Kolejka_.top();
        Kolejka_.pop();

     //   cout << "Wierzcholek " << tmp.wierzcholek << " - " << tmp.koszt << endl;

     //   cout << "ma " << Wierzcholki[tmp.wierzcholek].get_size() << " sasiadow." << endl;
        if(Tablica_wierzcholkow_odwiedzonych[tmp.wierzcholek]==0)
        {
            Tablica_wierzcholkow_odwiedzonych[tmp.wierzcholek]=1;

            for(int i=0; i<Wierzcholki[tmp.wierzcholek].get_size(); i++)
            {
                int D=Wierzcholki[tmp.wierzcholek].get(i);

            //    cout << "Sasiad wierzcholka " << tmp.wierzcholek << " " << D << endl;

                if(!tmp.lista.przeszukaj(D))
                {
              //      cout << "Nie ma wierzholka na liscie" << endl;
                    if(D==szukany)
                    {
                        if(tmp.koszt+waga_krawedzi[tmp.wierzcholek][D]<wynik)
                        {
                            wynik=tmp.koszt+waga_krawedzi[tmp.wierzcholek][D];
                        }
                    }
                    else
                    {
                        if(tmp.koszt+waga_krawedzi[tmp.wierzcholek][D]<wynik)
                        {
                            Lista L=tmp.lista.kopiuj();
                            L.dodaj(D,L.get_size());
                            Branch B(L,D,tmp.koszt+waga_krawedzi[tmp.wierzcholek][D]);
                            Kolejka_.push(B);

                        }
                    }
                }
            }
        }
        else{

        cout<<"JUZ BYLISMY W TYM WIERZCHOLKU";
        }
    }
    return wynik;

}
