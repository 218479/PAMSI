#include <iostream>
#include "Drzewo_Czerwono_Czarne.hh"
#include <cstdlib>
#include "stoper.hh"
#include "Test.hh"

using namespace std;

int main()
{
    int rozmiar[6]= {10,100,1000,10000,100000,1000000};
    Test Drzewo_testowe;

    for(int i=0;i<6;i++)
    Drzewo_testowe.wykonaj(rozmiar[i]);


    return 0;
}
