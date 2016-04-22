#include <iostream>
#include "Tablica_haszujaca.hh"
#include "stoper.hh"
#include "Test.hh"

using namespace std;

int main()
{

    Test Hasz;
    Hasz.wykonaj(10000);
    Hasz.wykonaj(1000);
    Hasz.wykonaj(100);
    Hasz.wykonaj(10);

    return 0;
}
