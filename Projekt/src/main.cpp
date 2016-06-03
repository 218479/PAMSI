#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "Plansza.hh"

using namespace std;

int main()
{
    Plansza p;
    int Kto_Ruch=1;
    int poziom_trudnosci=0;
    cout<<"\t\tWARCABY"<<endl;

    cout<<"Wybierz poziom trudnosci:\n1.latwy\n2.trudny"<<endl;

    do
    {
        cin>>poziom_trudnosci;
        switch(poziom_trudnosci)
        {
        case 1:
            poziom_trudnosci=2;
            break;
        case 2:
            poziom_trudnosci=4;
            break;
        default:
            cout<<"Wybierz poziom trudnosci:\n1.latwy\n2.trudny"<<endl;
            break;
        }
    }while(poziom_trudnosci!=2&&poziom_trudnosci!=4);

  system("clear");
    while(!p.Czy_Koniec(p))
    {
            //p.Wyswietl();
        Plansza::Ruch r;
        if (Kto_Ruch == 1)
        {
            p.Wyswietl();
            r = p.Gracz_Ruch(p);
            p = p.Zrob_Ruch(p,1, r.x, r.y, r.dx, r.dy);
        }
        else
        {
      system("clear");
            r = p.Komputer_Ruch(p,poziom_trudnosci);
            p = p.Zrob_Ruch(p,-1, r.x, r.y, r.dx, r.dy);
        }

        Kto_Ruch = -Kto_Ruch;
    }
    return 0;
}
