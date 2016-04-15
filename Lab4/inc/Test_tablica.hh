#ifndef TEST_TABLICA_HH
#define TEST_TABLICA_HH
#include "kolejka_head.h"
#include "cstdlib"
#include "timer.h"
#include <iostream>

using namespace std;

class Test_tablica
{
private:

    int *tab;
    int rozmiar;

    void wykonaj_quicksort2(int *tab, int lewy, int prawy);
    void wykonaj_quicksort1(int *tab, int lewy, int prawy);
public:
    Test_tablica(){
    rozmiar=0;
    tab=NULL;
    }
    ~Test_tablica(){
    delete [] tab;
    }
    void wykonaj();
    void wyswietl();
    int* get_tab();
    int get_rozmiar();
    void reset();
    void set_tablice(int x);
    void merge(int *tab,int lewy, int srodek, int prawy);
    void merge_sort(int *tab, int poczatek, int koniec);
    void merge_sort2(int *tab, int poczatek, int koniec);
    void merge_sort3(int *tab, int poczatek, int koniec);

};


#endif // TEST_TABLICA_HH
