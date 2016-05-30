#include <iostream>
#include <cstdlib>
#include "Graf.hh"
#include "Test.hh"


using namespace std;

int main()
{

 //   Test Nowy;
 //   Nowy.wykonaj();
    Graf Nowy(5);

    Nowy.ZrobPolaczenie(0,1,3);
    Nowy.ZrobPolaczenie(0,2,5);

    Nowy.ZrobPolaczenie(1,2,3);
    Nowy.ZrobPolaczenie(1,3,7);
    Nowy.ZrobPolaczenie(1,4,3);

    Nowy.ZrobPolaczenie(3,4,1);

    Nowy.CzyPolaczone(0,1);
    Nowy.CzyPolaczone(1,4);

    cout<<Nowy.BranchAndBoundWithExtendedList(4);
    cout<<"\n\n\n\n\n";
    cout<<Nowy.BranchAndBound(4);
    return 0;
}
