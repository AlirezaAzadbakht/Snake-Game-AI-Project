#include <iostream>
#include <cstdlib>  //baraie clear
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

void update();
void point_finder();
void shift(int,int);
void rasm();

int a[20][40]={0};
int snake_x[800]={0};
int snake_y[800]={0};
int sl=2;
int xx,yy;
int x_point,y_point;
int point_flag=0;

int main()
{
    int q=0,e=-1;
    int dead_flag=0;
    snake_x[0]=10;
    snake_x[1]=11;
    snake_y[0]=25;
    snake_y[1]=25;
    xx=12;
    yy=25;
    int cho=0;

    cout<<"enter the number\n1. AI\n2. W.A.S.D"<<endl;
    cin>>cho;

    system("cls");
    rasm();
    srand(time(0));
    point_finder();

    while(dead_flag!=1)
    {
        if(cho==2)
        {
            if(kbhit())
            {
                char x=_getch();
                    if(x==115){e=q=0;q=1;}
                else if(x==97) {e=q=0;e=-1;}
                else if(x==119){e=q=0;q=-1;}
                else if(x==100){e=q=0;e=1;}
            }
            if (a[xx+q][yy+e]!=0&&a[xx+q][yy+e]!=2)
            {
                dead_flag=1;
            }
            shift(xx+q,yy+e);
        }

        else
        {
                 if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx){shift((xx+1),yy);}
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx){shift((xx-1),yy);}
            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy){shift(xx,(yy+1));}
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy){shift(xx,(yy-1));}
            else if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      ){shift((xx+1),yy);}
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      ){shift((xx-1),yy);}
            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      ){shift(xx,(yy+1));}
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      ){shift(xx,(yy-1));}
            else {dead_flag=1;}
        }

        // colosh
        if (a[xx][yy]==a[x_point][y_point])
        {
            sl++;
            point_finder();
        }
        update();
        Sleep(50);

    }
    cout<< "\n\tGAME OVER"<< "\n\t score : "<<sl;
}

void shift(int x,int y)
{
   for (int i=sl;i>0;i--)
   {
      snake_x[i]=snake_x[i-1];
      snake_y[i]=snake_y[i-1];
   }
   snake_x[0]=xx;
   snake_y[0]=yy;
   xx=x;
   yy=y;

}


void point_finder()
{

   x_point=rand()%20;
   y_point=rand()%40;
   if (a[x_point][y_point]==0){a[x_point][y_point]=2;}
   else {point_finder();}
}


void update()
{



   system("cls");
   rasm();
   a[xx][yy]=4;
   for(int i=0;i<sl;i++)
   {
       a[snake_x[i]][snake_y[i]]=3;
   }


   for (int i=0;i<20;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(a[i][j]==0){cout<<" ";}
            else if(a[i][j]==1){cout<<"#";}
            else if(a[i][j]==2){cout<<"s";}
            else if(a[i][j]==3){cout<<"O";}
            else if(a[i][j]==4){cout<<"*";}
        }
        cout<<endl;
    }



}

void rasm()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<40;j++)
        {
            a[i][j]=0;
        }
    }
    a[x_point][y_point]=2;

    for(int i=0;i<40;i++)
    {
        a[0][i]=1;
        a[19][i]=1;
    }
    for(int i=0;i<20;i++)
    {
        a[i][0]=1;
        a[i][39]=1;
    }

}
