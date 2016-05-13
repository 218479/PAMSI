#ifndef STOPER_HH
#define STOPER_HH

#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

class stoper
{
private:
    time_t start, stop;
    double trwanie, suma;



public:
    stoper()
    {
        start=0;
        stop=0;
        trwanie=0;
        suma=0;

    };
    double get_trwanie()
    {
        return trwanie;
    }
    double get_suma()
    {
        return suma;
    }
    void Wlacz();
    void Wylacz();
    void Czas_trwania();
    void Zliczaj_do_sumy();
    void przygotuj();
};

#endif
