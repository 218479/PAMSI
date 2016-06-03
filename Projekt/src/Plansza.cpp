#include "Plansza.hh"

using namespace std;

Plansza::Plansza()
{
    int Tab_Temp[8][8]= {{0,-1,0,-1,0,-1,0,-1},
        {-1,0,-1,0,-1,0,-1,0},
        {0,-1,0,-1,0,-1,0,-1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0}
    };
    for(int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            Tablica[i][j]=Tab_Temp[i][j];
        }
    }
}
Plansza::Plansza(Plansza &p)
{
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            this->Tablica[x][y]=p.Tablica[x][y];
        }
    }
}

Plansza& Plansza::operator=(Plansza const &p2)
{
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            this->Tablica[x][y]=p2.Tablica[x][y];
        }
    }
    return *this;
}

void Plansza::Wyswietl()
{
    int int_set[8]= {8,7,6,5,4,3,2,1};
    cout<<endl<<"    A      B      C      D      E      F      G      H"<<endl;
    for(int i=0; i<8; i++)
    {
        cout<<int_set[i];
        for(int j=0; j<8; j++)
        {
            if(Tablica[i][j]==-1)
                cout<<"  [C]  ";
            if(Tablica[i][j]==-2)
                cout<<" [D_C] ";
            if(Tablica[i][j]==0)
                cout<<"  [ ]  ";
            if(Tablica[i][j]==1)
                cout<<"  [B]  ";
            if(Tablica[i][j]==2)
                cout<<" [D_B] ";
        }
        cout<<int_set[i]<<endl;
    }
    cout<<"    A      B      C      D      E      F      G      H"<<endl;
}

bool Plansza::Czy_Dozwolony_Ruch(Plansza p, int gracz, int x, int y, int dx, int dy)
{
    if(x>=0 && y>=0 && dx>=0 && dy>=0 && x<=7 && y<=7 && dx<=7 && dy<=7)
    {
        if(gracz==GRACZ && p.Tablica[y][x]==2)
        {
            if(dx>x && dy<y)
            {
                if( (dx==x+1 && dy==y-1) || (dx==x+2 && dy==y-2) ||
                        (dx==x+3 && dy==y-3) || (dx==x+4 && dy==y-4) ||
                        (dx==x+4 && dy==y-4) || (dx==x+5 && dy==y-5) ||
                        (dx==x+6 && dy==y-6) || (dx==x+7 && dy==y-7) )
                {
                    int temp_y=y-1;
                    for(int i=x+1; i<=dx; i++)
                    {
                        if(p.Tablica[temp_y][i]!=0)
                        {
                            if(p.Tablica[temp_y][i]!=1 && p.Tablica[temp_y][i]!=2)
                            {
                                if(temp_y!=0 || i!=7)
                                {
                                    if(p.Tablica[temp_y-1][i+1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp_y--;
                    }
                    return true;
                }
                return false;
            }

            if (dx>x && dy>y)
            {
                if( (dx==x+1 && dy==y+1) || (dx==x+2 && dy==y+2) ||
                        (dx==x+3 && dy==y+3) || (dx==x+4 && dy==y+4) ||
                        (dx==x+4 && dy==y+4) || (dx==x+5 && dy==y+5) ||
                        (dx==x+6 && dy==y+6) || (dx==x+7 && dy==y+7) )
                {
                    int temp_y=y+1;
                    for(int i=x+1; i<=dx; i++)
                    {
                        if(p.Tablica[temp_y][i]!=0)
                        {
                            if(p.Tablica[temp_y][i]!=1 && p.Tablica[temp_y][i]!=2)
                            {
                                if(temp_y!=7 || i!=7)
                                {
                                    if(p.Tablica[temp_y+1][i+1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp_y++;
                    }
                    return true;
                }
                return false;
            }

            if(dx<x && dy<y)
            {
                if( (dx==x-1 && dy==y-1) || (dx==x-2 && dy==y-2) ||
                        (dx==x-3 && dy==y-3) || (dx==x-4 && dy==y-4) ||
                        (dx==x-4 && dy==y-4) || (dx==x-5 && dy==y-5) ||
                        (dx==x-6 && dy==y-6) || (dx==x-7 && dy==y-7) )
                {
                    int temp_y=y-1;
                    for(int i=x-1; i>=dx; i--)
                    {
                        if(p.Tablica[temp_y][i]!=0)
                        {
                            if(p.Tablica[temp_y][i]!=1 && p.Tablica[temp_y][i]!=2)
                            {
                                if(temp_y!=0 || i!=0)
                                {
                                    if(p.Tablica[temp_y-1][i-1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp_y--;
                    }
                    return true;
                }
                return false;
            }

            if (dx<x && dy>y)
            {
                if( (dx==x-1 && dy==y+1) || (dx==x-2 && dy==y+2) ||
                        (dx==x-3 && dy==y+3) || (dx==x-4 && dy==y+4) ||
                        (dx==x-4 && dy==y+4) || (dx==x-5 && dy==y+5) ||
                        (dx==x-6 && dy==y+6) || (dx==x-7 && dy==y+7) )
                {
                    int temp_y=y+1;
                    for(int i=x-1; i>=dx; i--)
                    {
                        if(p.Tablica[temp_y][i]!=0)
                        {
                            if(p.Tablica[temp_y][i]!=1 && p.Tablica[temp_y][i]!=2)
                            {
                                if(temp_y!=7 || i!=0)
                                {
                                    if(p.Tablica[temp_y+1][i-1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp_y++;
                    }
                    return true;
                }
                return false;
            }        ;
        }

        if(gracz==KOMPUTER && p.Tablica[y][x]==-2)
        {
            if(dx>x && dy<y)
            {
                if( (dx==x+1 && dy==y-1) || (dx==x+2 && dy==y-2) ||
                        (dx==x+3 && dy==y-3) || (dx==x+4 && dy==y-4) ||
                        (dx==x+4 && dy==y-4) || (dx==x+5 && dy==y-5) ||
                        (dx==x+6 && dy==y-6) || (dx==x+7 && dy==y-7) )
                {
                    int temp_y=y-1;
                    for(int i=x+1; i<=dx; i++)
                    {
                        if(p.Tablica[temp_y][i]!=0)
                        {
                            if(p.Tablica[temp_y][i]!=-1 && p.Tablica[temp_y][i]!=-2)
                            {
                                if(temp_y!=0 || i!=7)
                                {
                                    if(p.Tablica[temp_y-1][i+1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp_y--;
                    }
                    return true;
                }
                return false;
            }

            if (dx>x && dy>y)
            {
                if( (dx==x+1 && dy==y+1) || (dx==x+2 && dy==y+2) ||
                        (dx==x+3 && dy==y+3) || (dx==x+4 && dy==y+4) ||
                        (dx==x+4 && dy==y+4) || (dx==x+5 && dy==y+5) ||
                        (dx==x+6 && dy==y+6) || (dx==x+7 && dy==y+7) )
                {
                    int temp_y=y+1;
                    for(int i=x+1; i<=dx; i++)
                    {
                        if(p.Tablica[temp_y][i]!=0)
                        {
                            if(p.Tablica[temp_y][i]!=-1 && p.Tablica[temp_y][i]!=-2)
                            {
                                if(temp_y!=7 || i!=7)
                                {
                                    if(p.Tablica[temp_y+1][i+1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp_y++;
                    }
                    return true;
                }
                return false;
            }

            if(dx<x && dy<y)
            {
                if( (dx==x-1 && dy==y-1) || (dx==x-2 && dy==y-2) ||
                        (dx==x-3 && dy==y-3) || (dx==x-4 && dy==y-4) ||
                        (dx==x-4 && dy==y-4) || (dx==x-5 && dy==y-5) ||
                        (dx==x-6 && dy==y-6) || (dx==x-7 && dy==y-7) )
                {
                    int temp_y=y-1;
                    for(int i=x-1; i>=dx; i--)
                    {
                        if(p.Tablica[temp_y][i]!=0)
                        {
                            if(p.Tablica[temp_y][i]!=-1 && p.Tablica[temp_y][i]!=-2 )
                            {
                                if(temp_y!=0 || i!=0)
                                {
                                    if(p.Tablica[temp_y-1][i-1]!=0)
                                    {
                                        return false;
                                    };
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp_y--;
                    }
                    return true;
                }
                return false;
            }

            if (dx<x && dy>y)
            {
                if( (dx==x-1 && dy==y+1) || (dx==x-2 && dy==y+2) ||
                        (dx==x-3 && dy==y+3) || (dx==x-4 && dy==y+4) ||
                        (dx==x-4 && dy==y+4) || (dx==x-5 && dy==y+5) ||
                        (dx==x-6 && dy==y+6) || (dx==x-7 && dy==y+7) )
                {
                    int temp_y=y+1;
                    for(int i=x-1; i>=dx; i--)
                    {
                        if(p.Tablica[temp_y][i]!=0)
                        {
                            if(p.Tablica[temp_y][i]!=-1 && p.Tablica[temp_y][i]!=-2)
                            {
                                if(temp_y!=7 || i!=0)
                                {
                                    if(p.Tablica[temp_y+1][i-1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp_y++;
                    }
                    return true;
                }
                return false;
            }
        }

        if(gracz==KOMPUTER)
        {
            if(p.Tablica[y][x]==-1)
            {
                if(p.Tablica[dy][dx]==0)
                {
                    if(dy==y+1)
                    {
                        if(dx==x+1||dx==x-1)
                        {
                            return true;
                        }
                    }
                }
                if(dy==y+2)
                {
                    if(dx==x+2)
                    {
                        if(p.Tablica[dy][dx]==0)
                        {
                            if(p.Tablica[y+1][x+1]>0)
                            {
                                return true;
                            }
                        }
                    }
                    if(dx==x-2)
                    {
                        if(p.Tablica[dy][dx]==0)
                        {
                            if(p.Tablica[y+1][x-1]>0)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else if(gracz==GRACZ)
        {
            if(p.Tablica[y][x]==1)
            {
                if(p.Tablica[dy][dx]==0)
                {
                    if(dy==y-1)
                    {
                        if(dx==x+1||dx==x-1)
                        {
                            return true;
                        }
                    }
                    if(dy==y-2)
                    {
                        if(dx==x+2)
                        {
                            if(p.Tablica[y-1][x+1]<0)
                            {
                                return true;
                            }
                        }
                        if(dx==x-2)
                        {
                            if(p.Tablica[y-1][x-1]<0)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Plansza::Czy_Koniec(Plansza p)
{
    int licz_biale=0;
    int licz_czarne=0;
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            if(p.Tablica[y][x]==1 || p.Tablica[y][x]==2)
                licz_biale++;
            if(p.Tablica[y][x]==-1 || p.Tablica[y][x]==-2)
                licz_czarne++;
        }
    }
    if(licz_biale==0 || licz_czarne==0)
        return true;
    else
        return false;
}

Plansza Plansza::Zrob_Ruch(const Plansza p, int gracz, int x, int y, int dx, int dy)
{

    Plansza wynik;
    wynik=p;

    if(wynik.Tablica[y][x]==2 || wynik.Tablica[y][x]==-2)
    {
        if(gracz==GRACZ)
        {
            if(dx>x && dy<y)
            {
                int temp_y=y-1;
                for(int i=x+1; i<=dx; i++)
                {
                    if(p.Tablica[temp_y][i]!=0)
                    {
                        wynik.Tablica[temp_y][i]=0;
                    }
                    temp_y--;
                }
                wynik.Tablica[dy][dx]=2;
                wynik.Tablica[y][x]=0;
            }

            if(dx>x && dy>y)
            {
                int temp_y=y+1;
                for(int i=x+1; i<=dx; i++)
                {
                    if(p.Tablica[temp_y][i]!=0)
                    {
                        wynik.Tablica[temp_y][i]=0;
                    }
                    temp_y++;
                }
                wynik.Tablica[dy][dx]=2;
                wynik.Tablica[y][x]=0;
            }

            if(dx<x && dy<y)
            {
                int temp_y=y-1;
                for(int i=x-1; i>=dx; i--)
                {
                    if(p.Tablica[temp_y][i]!=0)
                    {
                        wynik.Tablica[temp_y][i]=0;
                    }
                    temp_y--;
                }
                wynik.Tablica[dy][dx]=2;
                wynik.Tablica[y][x]=0;
            }

            if(dx<x && dy>y)
            {
                int temp_y=y+1;
                for(int i=x-1; i>=dx; i--)
                {
                    if(p.Tablica[temp_y][i]!=0)
                    {
                        wynik.Tablica[temp_y][i]=0;
                    }
                    temp_y++;
                }
                wynik.Tablica[dy][dx]=2;
                wynik.Tablica[y][x]=0;
            }
        }

        if(gracz==KOMPUTER)
        {

            if(dx>x && dy<y)
            {
                int temp_y=y-1;
                for(int i=x+1; i<=dx; i++)
                {
                    if(p.Tablica[temp_y][i]!=0)
                    {
                        wynik.Tablica[temp_y][i]=0;
                    }
                    temp_y--;
                }
                wynik.Tablica[dy][dx]=-2;
                wynik.Tablica[y][x]=0;
            }

            if(dx>x && dy>y)
            {
                int temp_y=y+1;
                for(int i=x+1; i<=dx; i++)
                {
                    if(p.Tablica[temp_y][i]!=0)
                    {
                        wynik.Tablica[temp_y][i]=0;
                    }
                    temp_y++;
                }
                wynik.Tablica[dy][dx]=-2;
                wynik.Tablica[y][x]=0;
            }

            if(dx<x && dy<y)
            {
                int temp_y=y-1;
                for(int i=x-1; i>=dx; i--)
                {
                    if(p.Tablica[temp_y][i]!=0)
                    {
                        wynik.Tablica[temp_y][i]=0;
                    }
                    temp_y--;
                }
                wynik.Tablica[dy][dx]=-2;
                wynik.Tablica[y][x]=0;
            }

            if(dx<x && dy>y)
            {
                int temp_y=y+1;
                for(int i=x-1; i>=dx; i--)
                {
                    if(p.Tablica[temp_y][i]!=0)
                    {
                        wynik.Tablica[temp_y][i]=0;
                    }
                    temp_y++;
                }
                wynik.Tablica[dy][dx]=-2;
                wynik.Tablica[y][x]=0;
            }
        }
    }

    if(gracz==GRACZ &&( (dy==0) || (dy==2) || (dy==4) || (dy==6)))
    {
        wynik.Tablica[dy][dx]=2;
    }
    if(gracz==KOMPUTER)
    {
        if(p.Tablica[y][x]==-1)
        {
            if(dy==y+1)
            {
                if(dx==x+1||dx==x-1)
                {
                    wynik.Tablica[dy][dx]=wynik.Tablica[y][x];
                    wynik.Tablica[y][x]=0;
                }
            }
            if(dy==y+2)
            {
                if(dx==x+2)
                {
                    if(wynik.Tablica[y+1][x+1]>0)
                    {
                        wynik.Tablica[y+1][x+1]=0;
                        wynik.Tablica[dy][dx]=wynik.Tablica[y][x];
                        wynik.Tablica[y][x]=0;
                    }
                }
                if(dx==x-2)
                {
                    if(p.Tablica[y+1][x-1]>0)
                    {
                        wynik.Tablica[y+1][x-1]=0;
                        wynik.Tablica[dy][dx]=wynik.Tablica[y][x];
                        wynik.Tablica[y][x]=0;
                    }
                }
            }
        }
    }
    else if(gracz==GRACZ)
    {
        if(p.Tablica[y][x]==1)
        {
            if(dy==y-1)
            {
                if(dx==x+1||dx==x-1)
                {
                    wynik.Tablica[dy][dx]=wynik.Tablica[y][x];
                    wynik.Tablica[y][x]=0;
                }
            }
            if(dy==y-2)
            {
                if(dx==x+2)
                {
                    if(p.Tablica[y-1][x+1]<0)
                    {
                        wynik.Tablica[y-1][x+1]=0;
                        wynik.Tablica[dy][dx]=p.Tablica[y][x];
                        wynik.Tablica[y][x]=0;
                    }
                }
                if(dx==x-2)
                {
                    if(p.Tablica[y-1][x-1]<0)
                    {
                        wynik.Tablica[y-1][x-1]=0;
                        wynik.Tablica[dy][dx]=wynik.Tablica[y][x];
                        wynik.Tablica[y][x]=0;
                    }
                }
            }
        }
    }
    if((dy==0 || dy==7))
    {
        if (gracz ==1)
        {
            wynik.Tablica[dy][dx]=2;
        }
        else
        {
            wynik.Tablica[dy][dx]=-2;
        }
    }
    return wynik;
}

int Plansza::Jak_Dobry_Stan(Plansza p)
{
    int wynik=0,wynik_gracza=0;
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            if(p.Tablica[x][y]==1)
            {
                wynik_gracza+=5;
            }
            else if(p.Tablica[x][y]==-1)
            {
                wynik+=5;
            }
            else if(p.Tablica[x][y]==2)
            {
                wynik_gracza+=100;
            }
            else if(p.Tablica[x][y]==-2)
            {
                wynik+=100;
            }
        }
    }
    wynik=wynik-wynik_gracza;
    return wynik;
}

int Plansza::Min_Max(Plansza p, int gracz, int glebokosc, Ruch &wynik)
{
    if (glebokosc == 0)
        return Jak_Dobry_Stan(p);

    int najlepszy;

    if (gracz == KOMPUTER) najlepszy = INT_MIN;
    else najlepszy = INT_MAX;

    Ruch naj_ruch;

    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
            for (int dx = 0; dx < 8; dx++)
                for (int dy = 0; dy < 8; dy++)
                {
                    if (Czy_Dozwolony_Ruch(p, gracz, x, y, dx, dy))
                    {
                        Plansza p_prim;
                        p_prim = Zrob_Ruch(p, gracz, x, y, dx, dy);
                        int jak_dobra = Min_Max(p_prim, -gracz, glebokosc-1, wynik);
                        if (gracz == KOMPUTER)
                        {
                            if (jak_dobra > najlepszy)
                            {
                                najlepszy = jak_dobra;
                                naj_ruch.x=x;
                                naj_ruch.y=y;
                                naj_ruch.dx=dx;
                                naj_ruch.dy=dy;
                            }
                        }
                        else
                        {
                            if (jak_dobra < najlepszy)
                            {
                                najlepszy = jak_dobra;
                                naj_ruch.x=x;
                                naj_ruch.y=y;
                                naj_ruch.dx=dx;
                                naj_ruch.dy=dy;
                            }
                        }
                    }
                }
    wynik=naj_ruch;
    return najlepszy;
}

Plansza::Ruch Plansza::Komputer_Ruch(Plansza p, int trudnosc)
{
    Ruch r;
    Min_Max(p, -1, trudnosc, r);
    cout<<endl<<"####  Komputer wykonal swoj ruch  ####"<<endl<<endl;
    return r;
}

Plansza::Ruch Plansza::Gracz_Ruch(Plansza p)
{
    Ruch r;
    string temp1, temp2;
    char char_temp1, char_temp2;
    int int_temp1, int_temp2;
    int intset[9]= {0,7,6,5,4,3,2,1,0};
    int x=0,y=0,dx=0,dy=0;

    cout<<endl<<"Kolej Gracza: "<<endl;
    while(!Czy_Dozwolony_Ruch(p,GRACZ,x,y,dx,dy))
    {
        cout<<"Wybierz pionek: ->";
        cin>>temp1;
        if(temp1.length()!=2)
        {
            cout<<endl<<"####### Bledne Wspolrzedne! #######"<<endl;
            continue;
        }
        cout<<"Wybierz pole docelowe: ->";
        cin>>temp2;
        if(temp2.length()!=2)
        {
            cout<<endl<<"####### Bledne Wspolrzedne! #######"<<endl;
            continue;
        }

        char_temp1=temp1[0];
        char_temp2=temp2[0];
        int_temp1=temp1[1]-48;
        int_temp2=temp2[1]-48;

        x=(int(char_temp1))-65;
        y=intset[int_temp1];
        dx=(int(char_temp2))-65;
        dy=intset[int_temp2];

        r.x=(int(char_temp1))-65;
        r.y=intset[int_temp1];
        r.dx=(int(char_temp2))-65;
        r.dy=intset[int_temp2];

        if(r.x>7 || r.x<0 || r.y>7 || r.y<0 ||
                r.dy>7 || r.dy<0 || r.dx>7 || r.dx<0)
        {
            cout<<endl<<"####### Bledne Wspolrzedne! #######"<<endl;
            continue;
        }
    }
    return r;
}
