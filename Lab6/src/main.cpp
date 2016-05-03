#include <iostream>
#include "Drzewo_Czerwono_Czarne.hh"
#include <cstdlib>
#include "stoper.hh"

using namespace std;

int main()
{
    stoper Czas;
    Drzewo Test;
    srand(time(NULL));
    int x=0;
    for(int i=0; i<1000; i++)
    {
        x=rand()%1000;
        cout<<x<<endl;
        Test.wstaw(x);
    }
    //Test.wyswietl();
    return 0;
}
