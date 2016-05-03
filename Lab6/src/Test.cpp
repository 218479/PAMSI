#include "Test.hh"

void Test::wykonaj(int x)
{
    Drzewo *Nowy;
    int y=0;
    int *szukane=new int[x];
    stoper Czas_szukania, Czas_wpisywania;

    srand(time(NULL));
    Czas_wpisywania.przygotuj();
    Czas_szukania.przygotuj();

    for(int i=0; i<10; i++)
    {
        Nowy=new Drzewo;
        szukane=new int [x];
        Czas_wpisywania.Wlacz();
        for(int i=0; i<x; i++)
        {
            y=rand();
            szukane[i]=y;
            Nowy->wstaw(y);
        }
        Czas_wpisywania.Wylacz();
        Czas_wpisywania.Czas_trwania();
        cout<<"Czas trwania zapisania: "<<Czas_wpisywania.get_trwanie()<<endl;
        Czas_wpisywania.Zliczaj_do_sumy();

        Czas_szukania.Wlacz();
        for(int i=0; i<x; i++)
        {
            Nowy->znajdz(szukane[i]);
        }
        Czas_szukania.Wylacz();
        Czas_szukania.Czas_trwania();
        cout<<"Czas szukania :"<<Czas_szukania.get_trwanie()<<endl;
        Czas_szukania.Zliczaj_do_sumy();
        Nowy->reset();
        delete [] szukane;

    }

    cout<<"\nSredni czas wpisywania "<<x<<" elementow: "<<Czas_wpisywania.get_suma()/10<<endl;
    cout<<"Sredni czas szukania "<<Czas_szukania.get_suma()/10<<endl<<endl;

}

void Test::przygotuj()
{

}
