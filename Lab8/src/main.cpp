#include <iostream>
#include <cstdlib>
#include "Graf.hh"
using namespace std;

int main()
{
    Graf Nowy(4);
    Nowy.ZrobPolaczenie(0,1);
    Nowy.ZrobPolaczenie(0,2);
    Nowy.ZrobPolaczenie(1,2);
    Nowy.ZrobPolaczenie(2,0);
    Nowy.ZrobPolaczenie(2,3);
    Nowy.ZrobPolaczenie(3,1);
    Nowy.CzyPolaczone(1,0);
    Nowy.CzyPolaczone(1,3);
    Nowy.CzyPolaczone(2,3);
   // Nowy.DFS();
    Nowy.BFS(3);
    return 0;
}
