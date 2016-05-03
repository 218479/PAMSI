#include "Drzewo_Czerwono_Czarne.hh"


void Drzewo::obroc_w_lewo(Wezel *x)
{
    Wezel *a, *b;

    a = x->prawy;
    if(a !=&lisc)
    {
        b = x->rodzic;
        x->prawy = a->lewy;
        if(x->prawy != &lisc)
        {
            x->prawy->rodzic = x;
        }
        a->lewy = x;
        a->rodzic = b;
        x->rodzic = a;

        if(b != &lisc)
        {
            if(b->lewy == x)
            {
                b->lewy = a;
            }
            else b->prawy = a;
        }
        else korzen = a;
    }
}
void Drzewo::obroc_w_prawo(Wezel *x)
{
    Wezel *a, *b;

    a = x->lewy;
    if(a !=&lisc)
    {
        b = x->rodzic;
        x->lewy = a->prawy;
        if(x->lewy != &lisc)
        {
            x->lewy->rodzic = x;
        }
        a->prawy = x;
        a->rodzic = b;
        x->rodzic = a;

        if(b != &lisc)
        {
            if(b->lewy == x)
            {
                b->lewy = a;
            }
            else b->prawy = a;
        }
        else korzen = a;
    }
}
void Drzewo::wstaw(int x)
{
    Wezel *wujek;
    Wezel *nowy=new Wezel;
    nowy->rodzic=korzen;
    nowy->lewy=&lisc;
    nowy->prawy=&lisc;
    nowy->wartosc=x;
    if(nowy->rodzic==&lisc)
    {
        korzen=nowy;
        korzen->kolor=0;
    }
    else
    {
        while(1)
        {
            if(nowy->rodzic->wartosc>x)
            {
                if(nowy->rodzic->lewy==&lisc)
                {
                    nowy->rodzic->lewy=nowy;
                    nowy->kolor=1;
                    break;
                }
                nowy->rodzic=nowy->rodzic->lewy;
            }
            else
            {
                if(nowy->rodzic->prawy==&lisc)
                {
                    nowy->rodzic->prawy=nowy;
                    nowy->kolor=1;
                    break;
                }
                nowy->rodzic=nowy->rodzic->prawy;
            }
        }
    }
    while(nowy!=korzen&&nowy->rodzic->kolor==1)
    {
        if(nowy->rodzic==nowy->rodzic->rodzic->lewy)
        {
            wujek=nowy->rodzic->rodzic->prawy;
            if(wujek->kolor==1)
            {
                nowy->rodzic->kolor=0;
                wujek->kolor=0;
                nowy->rodzic->rodzic->kolor=1;
                nowy=nowy->rodzic->rodzic;
                continue;
            }
            if(nowy==nowy->rodzic->prawy)
            {
                nowy=nowy->rodzic;
                obroc_w_lewo(nowy);
            }
            nowy->rodzic->kolor=0;
            nowy->rodzic->rodzic->kolor=1;
            obroc_w_prawo(nowy->rodzic->rodzic);
            break;
        }
        else
        {
            wujek=nowy->rodzic->rodzic->lewy;
            if(wujek->kolor==1)
            {
                nowy->rodzic->kolor=0;
                wujek->kolor=0;
                nowy->rodzic->rodzic->kolor=1;
                nowy=nowy->rodzic->rodzic;
                continue;
            }
            if(nowy==nowy->rodzic->lewy)
            {
                nowy=nowy->rodzic;
                obroc_w_prawo(nowy);
            }
            nowy->rodzic->kolor=0;
            nowy->rodzic->rodzic->kolor=1;
            obroc_w_lewo(nowy->rodzic->rodzic);
            break;
        }
    }
    korzen->kolor=0;
}

void Drzewo::wypisz(Wezel *x)
{
    if (x != &lisc)
    {
        wypisz (x->lewy);
        wypisz (x-> prawy);
        if(x->kolor==1)
            cout << x->wartosc << "R ";
        else cout<<x->wartosc<<"B ";
    }
}
void Drzewo::wyswietl()
{
    wypisz(korzen);
}
int Drzewo::znajdz(int x)
{
    int z=0;
    Wezel *tmp;
    tmp=korzen;
    while(tmp!=&lisc)
    {
        z++;
        if(tmp->wartosc>x)
        {
            tmp=tmp->lewy;
        }
        else if(tmp->wartosc<x)
        {
            tmp=tmp->prawy;
        }
        else
        {
            return x;
        }
    }
    return NULL;
}
void Drzewo::usun(Wezel *x)
{
    if(x!=&lisc)
    {
        usun(x->prawy);
        usun(x->lewy);
        delete x;
    }
}
void Drzewo::reset()
{
    usun(korzen);
    lisc.kolor=0;
    lisc.rodzic=&lisc;
    lisc.prawy=&lisc;
    lisc.lewy=&lisc;
    korzen=&lisc;

}
