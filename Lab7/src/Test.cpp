#include "Test.hh"

void Test::przygotuj()
{

}

void Test::wykonaj()
{
    Graf *Nowy;
    stoper Czas_przeszukania_DFS,Czas_przeszukania_BFS;
    int rozmiar[6]= {10,100,1000,10000,100000,1000000};
    int i;

    for(i=0; i<6; i++)
    {
        Czas_przeszukania_DFS.przygotuj();
        Czas_przeszukania_BFS.przygotuj();
        for(int k=0; k<20; k++)
        {
            Nowy=new Graf(rozmiar[i]);
            for(int j=0; j<rozmiar[i]/2; j++)
            {
                Nowy->ZrobPolaczenie(j,j*2);
                Nowy->ZrobPolaczenie(j,(j+1)*2-1);
            }
            Czas_przeszukania_DFS.Wlacz();
            Nowy->DFS();
            Czas_przeszukania_DFS.Wylacz();
            Czas_przeszukania_DFS.Czas_trwania();
            Czas_przeszukania_DFS.Zliczaj_do_sumy();
            Czas_przeszukania_BFS.Wlacz();
            Nowy->BFS();
            Czas_przeszukania_BFS.Wylacz();
            Czas_przeszukania_BFS.Czas_trwania();
            Czas_przeszukania_BFS.Zliczaj_do_sumy();
            delete Nowy;
        }
        cout<<"Czas przejscia grafu "<<rozmiar[i]<<" elementowego trwal dla DFS: "<<Czas_przeszukania_DFS.get_suma()/20<<endl;
        cout<<"Czas przejscia grafu "<<rozmiar[i]<<" elementowego trwal dla BFS: "<<Czas_przeszukania_BFS.get_suma()/20<<endl;
    }

}
