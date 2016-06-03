#ifndef PLANSZA_HH
#define PLANSZA_HH

#include <iostream>
#include <climits>

#define KOMPUTER -1
#define GRACZ 1

class Plansza
{
    int Tablica[8][8];
public:
    struct Ruch
    {
        int x,y,dx,dy;
        Ruch() {}
        Ruch(int get_x, int get_y, int get_dx, int get_dy)
        {
            x=get_x;
            y=get_y;
            dx=get_dx;
            dy=get_dy;
        }
    };
    Plansza();
    Plansza(Plansza &p);
    Plansza& operator=(Plansza const &p2);
    void Wyswietl();
    bool Czy_Dozwolony_Ruch(Plansza p, int gracz, int x, int y, int dx, int dy);
    bool Czy_Koniec(Plansza p);
    Plansza Zrob_Ruch(const Plansza p, int gracz, int x, int y, int dx, int dy);
    int Jak_Dobry_Stan(Plansza p);
    int Min_Max(Plansza p, int gracz, int glebokosc, Ruch &wynik);
    Ruch Komputer_Ruch(Plansza p, int trudnosc);
    Ruch Gracz_Ruch(Plansza p);
};
#endif
