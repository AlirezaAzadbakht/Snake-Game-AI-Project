#ifndef SNAKE_FUN_H_INCLUDED
#define SNAKE_FUN_H_INCLUDED

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

int q=0,e=-1;
int dead_flag=0;
int cho=0;
int temp_flag=0;

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
    cout<<sl;



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


#endif // SNAKE_FUN_H_INCLUDED
