#include "Test.hh"

void Test::przygotuj()
{

}

void Test::wykonaj()
{
    Graf *Nowy;
    stoper Czas_przeszukania_BB,Czas_przeszukania_BBWEL;
    int rozmiar[4]= {10,100,1000,10000};
    int i;
    srand(time(NULL));
    for(i=0; i<4; i++)
    {
        Czas_przeszukania_BB.przygotuj();
        Czas_przeszukania_BBWEL.przygotuj();
        for(int k=0; k<10; k++)
        {
            Nowy=new Graf(rozmiar[i]);
            for(int j=0; j<rozmiar[i]; j++)
            {
                Nowy->ZrobPolaczenie(j,rand()%(rozmiar[i]),rand()%200);
                Nowy->ZrobPolaczenie(rand()%(rozmiar[i]),rand()%(rozmiar[i]),rand()%200);
            }
     /*       for(int j=1; j<rozmiar[i]/2; j++)
            {
                for(int i=0; i<rozmiar[i]; i++)
                {
                    cout<<"Wierzcholek"<<i<<" i "<<j<<" ";
                    Nowy->CzyPolaczone(i,j);
                }
            }*/
            Czas_przeszukania_BB.Wlacz();
            //cout<<"Droga BB wynosi: "<<Nowy->BranchAndBound(rozmiar[i]-1)<<endl;
            Czas_przeszukania_BB.Wylacz();
            Czas_przeszukania_BB.Czas_trwania();
            Czas_przeszukania_BB.Zliczaj_do_sumy();
            Czas_przeszukania_BBWEL.Wlacz();
            //cout<<"Droga BbWLE wynosi: "<<Nowy->BranchAndBoundWithExtendedList(rozmiar[i]-1)<<endl;
            Czas_przeszukania_BBWEL.Wylacz();
            Czas_przeszukania_BBWEL.Czas_trwania();
            Czas_przeszukania_BBWEL.Zliczaj_do_sumy();
            delete Nowy;
        }
         cout<<"Czas przejscia grafu "<<rozmiar[i]<<" elementowego trwal dla Branch&Bound: "<<Czas_przeszukania_BB.get_suma()/10<<endl;
         cout<<"Czas przejscia grafu "<<rozmiar[i]<<" elementowego trwal dla Branch&Bound with extended list: "<<Czas_przeszukania_BBWEL.get_suma()/10<<endl;
    }

}
