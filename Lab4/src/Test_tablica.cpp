#include "Test_tablica.hh"

void Test_tablica::set_tablice(int x)
{
    srand(time(NULL));
    if(rozmiar>0)
    {
        delete [] tab;
    }
    rozmiar=x;
    tab=new int [rozmiar];
    for(int i=0; i<rozmiar; i++)
    {
        tab[i]=rand();
    }
}

int* Test_tablica::get_tab()
{
    return tab;
}


int Test_tablica::get_rozmiar()
{
    return rozmiar;
}


void Test_tablica::reset()
{
    srand(time(NULL));
    if(rozmiar>0)
    {
        delete [] tab;
    }
    tab=new int [rozmiar];

    for(int i=0; i<rozmiar; i++)
    {
        tab[i]=rand();
    }
}


void Test_tablica::wyswietl()
{
    for(int i=0; i<rozmiar; i++)
    {
        cout<<tab[i]<<" ";
    }
}

void Test_tablica::wykonaj_quicksort1(int *tab, int left, int right)
{
    int p, q, pivot;
    p=left;
    q=right;
    pivot=tab[(left+right)/2];
    do
    {
        while(tab[p]<pivot)
        {
            p++;
        }
        while(tab[q]>pivot)
        {
            q--;
        }
        if(p<=q)
        {
            int temp=tab[p];
            tab[p]=tab[q];
            tab[q]=temp;
            p++;
            q--;
        }
    }
    while(p<=q);
    if(q>left)
    {
        wykonaj_quicksort1(tab,left,q);
    }
    if(p<right)
    {
        wykonaj_quicksort1(tab,p,right);
    }

}


void Test_tablica::wykonaj_quicksort2(int *tab, int left, int right)
{
    int p, q, pivot;
    p=left;
    q=right;
    pivot=tab[p];
    do
    {
        while(tab[p]<pivot)
        {
            p++;
        }
        while(tab[q]>pivot)
        {
            q--;
        }
        if(p<=q)
        {
            int temp=tab[p];
            tab[p]=tab[q];
            tab[q]=temp;
            p++;
            q--;
        }
    }
    while(p<=q);
    if(q>left)
    {
        wykonaj_quicksort2(tab,left,q);
    }
    if(p<right)
    {
        wykonaj_quicksort2(tab,p,right);
    }
}

void Test_tablica::merge(int *tab,int lewy, int pivot, int prawy)
{
    int *pom=new int [prawy+1-lewy];
    int i, j, k;
    i=lewy;
    j=pivot+1;
    k=0;
    while((i<=pivot)&&(j<=prawy))
    {
        if(tab[j]<tab[i])
        {
            pom[k]=tab[j];
            j++;
            k++;
        }
        else
        {
            pom[k]=tab[i];
            i++;
            k++;
        }

    }
    if(i<=pivot)
    {

        while(i<=pivot)
        {
            pom[k]=tab[i];
            i++;
            k++;
        }
    }
    else
    {
        while(j<=prawy)
        {
            pom[k]=tab[j];
            j++;
            k++;
        }
    }
    for(i=0; i<=prawy-lewy; i++)
    {
        tab[lewy+i]=pom[i];
    }
    delete [] pom;
}

void Test_tablica::merge_sort(int *tab, int poczatek, int koniec)
{
    int pivot;

    if(poczatek<koniec)
    {
        pivot=(poczatek+koniec)/2;
        merge_sort(tab,poczatek,pivot);
        merge_sort(tab,pivot+1,koniec);
        merge(tab,poczatek,pivot,koniec);
    }

}

void Test_tablica::merge_sort2(int *tab, int poczatek, int koniec)
{
    int pivot;

    if(poczatek<koniec)
    {
        pivot=poczatek;
        merge_sort(tab,poczatek,pivot);
        merge_sort(tab,pivot+1,koniec);
        merge(tab,poczatek,pivot,koniec);
    }

}

void Test_tablica::merge_sort3(int *tab, int poczatek, int koniec)
{
    int pivot;

    if(poczatek<koniec)
    {
        pivot=rand()%koniec;
        merge_sort(tab,poczatek,pivot);
        merge_sort(tab,pivot+1,koniec);
        merge(tab,poczatek,pivot,koniec);
    }

}




void Test_tablica::wykonaj()
{
    timer stoper;
    stoper.przygotuj();
    for(int i=0; i<10; i++)
    {
        stoper.start_clock();
        wykonaj_quicksort1(tab,0,rozmiar-1);
        stoper.stop_clock();
        stoper.get_time();
        stoper.dodaj_sume();
        reset();
    }
    cout<<"pivot w srodku"<<endl;
    cout<<"sredni czas dla posortowania "<<rozmiar<<" elementow to: \t"<<stoper.get_suma()/10<<endl;
    stoper.przygotuj();
    for(int i=0; i<10; i++)
    {
        stoper.start_clock();
        wykonaj_quicksort2(tab,0,rozmiar-1);
        stoper.stop_clock();
        stoper.get_time();
        stoper.dodaj_sume();
        reset();
    }
    cout<<"pivot na poczatku"<<endl;
    cout<<"sredni czas dla posortowania "<<rozmiar<<" elementow to: \t"<<stoper.get_suma()/10<<endl;
    stoper.przygotuj();
    for(int i=0; i<10; i++)
    {

        stoper.start_clock();
        merge_sort(tab,0,rozmiar-1);
        stoper.stop_clock();
        stoper.get_time();
        stoper.dodaj_sume();
        reset();
    }
    cout<<"Mergesort - pivot w srodku"<<endl;
    cout<<"sredni czas dla posortowania "<<rozmiar<<" elementow to: \t"<<stoper.get_suma()/10<<endl;
    stoper.przygotuj();
    for(int i=0; i<10; i++)
    {

        stoper.start_clock();
        merge_sort2(tab,0,rozmiar-1);
        stoper.stop_clock();
        stoper.get_time();
        stoper.dodaj_sume();
        reset();
    }
    cout<<"Mergesort - pivot na poczatku"<<endl;
    cout<<"sredni czas dla posortowania "<<rozmiar<<" elementow to: \t"<<stoper.get_suma()/10<<endl;
    stoper.przygotuj();
    for(int i=0; i<10; i++)
    {

        stoper.start_clock();
        merge_sort3(tab,0,rozmiar-1);
        stoper.stop_clock();
        stoper.get_time();
        stoper.dodaj_sume();
        reset();
    }
    cout<<"Mergesort - pivot losowo"<<endl;
    cout<<"sredni czas dla posortowania "<<rozmiar<<" elementow to: \t"<<stoper.get_suma()/10<<endl;
}




