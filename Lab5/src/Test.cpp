#include "Test.hh"

void Test::wykonaj(int rozmiar_tablicy)
{
    ifstream plik;
    string nazwa;
    plik.open("nowy.txt");
    stoper Czas, Czas_szukania;
    Tablica_haszujaca Tablica(rozmiar_tablicy);

    int tab[5]= {10,100,1000,10000,100000};
    int j=0;

    for(j=0; j<5; j++)
    {
        Czas.przygotuj();
        Czas_szukania.przygotuj();
        for(int i=0; i<10; i++)
        {
            Czas.Wlacz();
            for(int i=0; i<tab[j]; i++)
            {
                plik>>nazwa;
                Tablica.wloz(nazwa);
            }
            Czas.Wylacz();
            Czas_szukania.Wlacz();
            Tablica.znajdz("wolska");
            Czas_szukania.Wylacz();
            Czas_szukania.Czas_trwania();
            Czas.Czas_trwania();
            Czas_szukania.Zliczaj_do_sumy();
            Czas.Zliczaj_do_sumy();
            Tablica.reset();
        }
        cout<<"Zapisywanie "<<tab[j]<<" elementow do tablicy o rozmiarze "<<rozmiar_tablicy<<" trwalo "<<Czas.get_suma()/10<<endl;
        cout<<"Czas przeszukania tablicy o "<<tab[j]<<" liczbie bucketow i "<<rozmiar_tablicy<<"l. elementow trwalo"<<Czas_szukania.get_suma()/10<<endl;
    }

}

void Test::przygotuj()
{
}
