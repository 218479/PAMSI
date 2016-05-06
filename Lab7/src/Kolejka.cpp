#include "Kolejka.hh"
void Kolejka::push(int x)
{
this->dodaj(x,this->Rozmiar());
}
int Kolejka::pop()
{
    int temp=this->get(0);
    this->usun(0);
    return temp;
}
int Kolejka::Rozmiar()
{
    return this->get_size();
}
