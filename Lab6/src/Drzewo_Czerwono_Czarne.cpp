#include "Drzewo_Czerwono_Czarne.hh"


void Drzewo::obroc_w_lewo(Wezel *x)
{
    Wezel*p,*q;
    p=x->prawy;
    if(p!=NULL)
    {
        q=x->rodzic;
        x->prawy=p->lewy;
        if(p->prawy!=NULL)
        {
            p->prawy->rodzic=x;
        }
        p->lewy=x;
        p->rodzic=q;
        x->rodzic=p;
        if(q!=NULL)
        {
            if(q->lewy==x)
            {
                q->lewy=p;
            }
            else
                q->prawy=p;
        }
        else korzen=p;
    }
}
void Drzewo::obroc_w_prawo(Wezel *x)
{
    Wezel * p, * q;
    p = x->lewy;
    if(p != NULL)
    {
        q = x->rodzic;
        x->lewy = p->prawy;
        if(x->lewy !=NULL) x->lewy->rodzic = x;

        p->prawy =x;
        p->rodzic = q;
        x->rodzic = p;

        if(q != NULL)
        {
            if(q->lewy == x) q->lewy = p;
            else q->prawy = p;
        }
        else korzen = p;
    }

}
void Drzewo::wstaw(int x)
{
    Wezel *tmp, *wujek;
    Wezel *nowy=new Wezel(x);
    if(korzen==NULL)
    {
        cout<<"DODANO KORZEN"<<endl;
        korzen=nowy;
        korzen->kolor=0;
        korzen->rodzic=NULL;
    }
    else
    {
        nowy->lewy=NULL;
        nowy->prawy=NULL;
        tmp=korzen;
        while(1)
        {
           // cout<<"cos8"<<endl;
            if(tmp->wartosc>x)
            {
                if(tmp->lewy==NULL)
                {
                    tmp->lewy=nowy;
                    nowy->kolor=1;
                    nowy->rodzic=tmp;
                    break;
                }
                else{
                tmp=tmp->lewy;
             //   cout<<"cos9"<<endl;
             }
            }
            else
            {
                if(tmp->prawy==NULL)
                {
                    tmp->prawy=nowy;
                    nowy->kolor=1;
                    nowy->rodzic=tmp;
                    break;
                }
                else{
                tmp=tmp->prawy;
            //    cout<<"cos10"<<endl;
             }
            }
        }
    }
    tmp=nowy;
    while(tmp->rodzic!=NULL&&tmp->rodzic->kolor==1)
    {
      //  cout<<"cos"<<endl;
        if(tmp->rodzic==tmp->rodzic->rodzic->lewy)
        {
            wujek=tmp->rodzic->rodzic->prawy;
            if(wujek!=NULL&&wujek->kolor==1)
            {
         //       cout<<"cos1"<<endl;
                tmp->rodzic->kolor=0;
                wujek->kolor=0;
                tmp=tmp->rodzic->rodzic;
                tmp->kolor=1;
                continue;
            }
            if((tmp==tmp->rodzic->prawy)&&(wujek!=NULL)&&(wujek->kolor==0))
            {
                tmp=tmp->rodzic;
                obroc_w_lewo(tmp);
         //       cout<<"cos2"<<endl;
            }
            tmp->rodzic->kolor=0;
            tmp->rodzic->rodzic->kolor=1;
            obroc_w_prawo(tmp->rodzic);
         //   cout<<"cos3"<<endl;
            break;
        }
        else
        {
            wujek=tmp->rodzic->rodzic->lewy;
            if(wujek!=NULL&&wujek->kolor==1)
            {
          //      cout<<"cos4"<<endl;
                tmp->rodzic->kolor=0;
                wujek->kolor=0;
                tmp=tmp->rodzic->rodzic;
                tmp->kolor=1;
                continue;
            }
            if((tmp==tmp->rodzic->lewy)&&(wujek!=NULL)&&(wujek->kolor==0))
            {
                tmp=tmp->rodzic;
                obroc_w_prawo(tmp);
           //     cout<<"cos5"<<endl;
            }
            tmp->rodzic->kolor=0;
            tmp->rodzic->rodzic->kolor=1;
            obroc_w_lewo(tmp->rodzic);
         //   cout<<"cos6"<<endl;
            break;
        }
    }
   // cout<<"cos7"<<endl;
    korzen->kolor=0;
}

void Drzewo::wypisz(Wezel *x)
{
    if (x != NULL)
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
    /*  cout<<korzen->wartosc<<endl;
      cout<<korzen->lewy->wartosc<<endl;
      cout<<korzen->prawy->wartosc<<endl;*/
}
int Drzewo::znajdz(int x)
{
    int z=0;
    Wezel *tmp;
    tmp=korzen;
    while(tmp!=NULL)
    {
        z++;
        if(x==tmp->wartosc)
        {
            cout<<"Znaleziono element, po przejsciu "<<z<<" wezlow"<<endl;
            return x;
        }
        else if(x>tmp->wartosc)
        {
            tmp=tmp->prawy;
        }
        else
            tmp=tmp->lewy;
    }
    cout<<"Nie znaleziono elementu"<<endl;
}
/*void Drzewo::usun(Wezel *x)
{
    if(x!=NULL)
    {
        usun(x->prawy);
        usun(x->lewy);
        delete x;
    }
}*/
