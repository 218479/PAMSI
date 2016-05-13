#include "Lista.hh"

void Lista::dodaj(int x,int nr)
{
    Element *tmp=new Element(x);
    if(nr==0)
    {
        if(get_size()==0)
        {
            poczatek=koniec=tmp;
        }
        else
        {
            tmp->nastepny=poczatek;
            poczatek=tmp;
        }
    }
    else if(nr==get_size())
    {
        if(this->get_size()==0)
        {
            poczatek=koniec=tmp;
        }
        else
        {
            koniec->nastepny=tmp;
            koniec=tmp;
            koniec->nastepny=NULL;
        }
    }
    else
    {
        if(get_size()<nr)
        {
            cout<<"Nie da się dodac w wybrane miejsce! Za malo danych"<<endl;
        }
        else
        {
            int i=1;
            Element *q;
            Element *p;
            p=poczatek;
            while(i<nr)
            {
                p=p->nastepny;
                i++;
            }
            q=p->nastepny;
            p->nastepny=tmp;
            p=tmp;
            p->nastepny=q;
        }
    }

}
void Lista::usun(int pozycja)
{
    Element* tmp=poczatek;

    if(pozycja==0)
    {
        poczatek=poczatek->nastepny;
        delete tmp;
        tmp=poczatek;
    }

    else if(pozycja==get_size())
    {
        int i=0;

        while(i<(get_size()-2))
        {
            i++;
            tmp=tmp->nastepny;
        }
        koniec=tmp;
        koniec->nastepny=NULL;
    }
    else
    {
        if(get_size()<pozycja)
        {
            cout<<"Nie da się dodac w wybrane miejsce! Za malo danych"<<endl;
        }
        else
        {
            int i=0;

            Element *p=poczatek;
            Element *q=poczatek;
            while(i<pozycja)
            {
                i++;
                p=p->nastepny;

            }
            q=p->nastepny->nastepny;
            p->nastepny=q;
        }
    }
}
int Lista::get(int nr)
{
    int i=1;
    Element *tmp=poczatek;
    if(nr>this->get_size())
    {
        cout<<"NIE DA SIE SCIAGNAC TEGO ELEMENTU"<<endl;
    }
    if(nr==1)
    {
        tmp=tmp->nastepny;
        return tmp->dana;
    }
    while(i<nr)
    {
        i++;
        tmp=tmp->nastepny;

    }
    return tmp->dana;

}
int Lista::get_size()
{
    int i=0;
    Element *tmp=poczatek;
    while(tmp)
    {
        i++;
        tmp=tmp->nastepny;
    }
    return i;
}

int Lista::przeszukaj(int a)
{
    int x=0,y=0;
    Element *tmp=poczatek;
    while(tmp)
    {
        y++;
        if(tmp->dana==a)
        {
            x++;
            return a;
        }
        tmp=tmp->nastepny;
    }

}
