#include "Tablica_haszujaca.hh"


int Tablica_haszujaca::znajdz(string klucz)
{
    string osoba=klucz;
    int x=haszuj(klucz);
    for(int i=0;i<10;i++)
    {
        if(x=Tablica[i])
        {
            Lista Zmienna=Tablica[i];
            Zmienna.przeszukaj(osoba);
        }
    }
}

void Tablica_haszujaca::wloz(string klucz, int dana)
{
    int x=klucz.haszuj();
    for(int i=0;i<10;i++){
        if(x=Tablica[i])
        {
            Lista Zmienna=Tablica[i];
            Zmienna.push(osoba,0);
        }
    }
}

void Tablica_haszujaca::usun(string klucz, int dana)
{
}
void Tablica_haszujaca::haszuj()
{
}

