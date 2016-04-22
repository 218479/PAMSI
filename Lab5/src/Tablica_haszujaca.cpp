#include "Tablica_haszujaca.hh"


void Tablica_haszujaca::znajdz(string klucz)
{
    int x=haszuj(klucz);
    Tablica[x].przeszukaj(klucz);

}

void Tablica_haszujaca::wloz(string klucz)
{
    int x=haszuj(klucz);
    Tablica[x].dodaj(klucz,0);

}

int Tablica_haszujaca::haszuj(string klucz)
{
    unsigned int kod=0;
    unsigned int i=0;
    unsigned int dlugosc=klucz.length();

    for(i=0; i<dlugosc; i++)
    {
        kod=(klucz[i])+(kod<<6)+(kod<<16)-kod;
    }

    return kod%rozmiar;
}

void Tablica_haszujaca::reset()
{
    delete [] Tablica;
    Tablica=new Lista[rozmiar];
}


