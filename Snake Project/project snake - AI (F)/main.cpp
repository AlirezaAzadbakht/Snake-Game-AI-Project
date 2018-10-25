#include <iostream>
#include <cstdlib>  //baraie clear
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "snake_fun.h"

using namespace std;

/*void update();
void point_finder();
void shift(int,int);
void rasm();*/

//int a[20][40]={0};
//int snake_x[800]={0};
//int snake_y[800]={0};
//int sl=2;
//int xx,yy;
//int x_point,y_point;
//int point_flag=0;

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
    int temp_flag=0;

    cout<<"enter the number\n1. AI\n2. W.A.S.D"<<endl;
    cin>>cho;

    system("cls");
    rasm();
    srand(time(0));
    point_finder();

    while(dead_flag!=1)
    {
        if(cho==2) // W A S D
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

        else // A I
        {
            //1
                 if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx)//a
                {
                    temp_flag=0;
                    for(int i=xx;i<20;i++)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx+1),yy);}
                }
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx)//b
                {
                    temp_flag=0;
                    for(int i=xx;i>=0;i--)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx-1),yy);}
                }
            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy)//c
                {
                    temp_flag=0;
                    for(int i=yy;i<40;i++)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy+1));}
                }
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy)//d
                {
                    temp_flag=0;
                    for(int i=yy;i>0;i--)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy-1));}
                }
            else if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      ){shift((xx+1),yy);}
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      ){shift((xx-1),yy);}
            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      ){shift(xx,(yy+1));}
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      ){shift(xx,(yy-1));}
            else {dead_flag=1;}








            //2
            if(temp_flag==1)
            {
             if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy)//c
                {
                    temp_flag=0;
                    for(int i=yy;i<40;i++)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy+1));}
                }
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy)//d
                {
                    temp_flag=0;
                    for(int i=yy;i>0;i--)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy-1));}
                }
            else if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx)//a
                {
                    temp_flag=0;
                    for(int i=xx;i<20;i++)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx+1),yy);}
                }
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx)//b
                {
                    temp_flag=0;
                    for(int i=xx;i>=0;i--)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx-1),yy);}
                }

            }
            //3
            if(temp_flag==1)
            {
            if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx)//b
                {
                    temp_flag=0;
                    for(int i=xx;i>=0;i--)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx-1),yy);}
                }
            else if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx)//a
                {
                    temp_flag=0;
                    for(int i=xx;i<20;i++)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx+1),yy);}
                }

            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy)//c
                {
                    temp_flag=0;
                    for(int i=yy;i<40;i++)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy+1));}
                }
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy)//d
                {
                    temp_flag=0;
                    for(int i=yy;i>0;i--)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy-1));}
                }
            }
            //4
            if(temp_flag==1)
            {
            if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy)//d
                {
                    temp_flag=0;
                    for(int i=yy;i>0;i--)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy-1));}
                }
            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy)//c
                {
                    temp_flag=0;
                    for(int i=yy;i<40;i++)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy+1));}
                }

            else if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx)//a
                {
                    temp_flag=0;
                    for(int i=xx;i<20;i++)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx+1),yy);}
                }
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx)//b
                {
                    temp_flag=0;
                    for(int i=xx;i>=0;i--)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx-1),yy);}
                }
            }
            //5
            if(temp_flag==1)
            {
            if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx)//a
                {
                    temp_flag=0;
                    for(int i=xx;i<20;i++)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx+1),yy);}
                }
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx)//b
                {
                    temp_flag=0;
                    for(int i=xx;i>=0;i--)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx-1),yy);}
                }
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy)//d
                {
                    temp_flag=0;
                    for(int i=yy;i>0;i--)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy-1));}
                }
            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy)//c
                {
                    temp_flag=0;
                    for(int i=yy;i<40;i++)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy+1));}
                }

            }
            //6
            if(temp_flag==1)
            {

            if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy)//c
                {
                    temp_flag=0;
                    for(int i=yy;i<40;i++)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy+1));}
                }
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy)//d
                {
                    temp_flag=0;
                    for(int i=yy;i>0;i--)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy-1));}
                }
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx)//b
                {
                    temp_flag=0;
                    for(int i=xx;i>=0;i--)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx-1),yy);}
                }
            else if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx)//a
                {
                    temp_flag=0;
                    for(int i=xx;i<20;i++)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx+1),yy);}
                }
            }
            //7
            if(temp_flag==1)
            {
            if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx)//b
                {
                    temp_flag=0;
                    for(int i=xx;i>=0;i--)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx-1),yy);}
                }
            else if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx)//a
                {
                    temp_flag=0;
                    for(int i=xx;i<20;i++)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx+1),yy);}
                }
            else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy)//d
                {
                    temp_flag=0;
                    for(int i=yy;i>0;i--)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy-1));}
                }
            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy)//c
                {
                    temp_flag=0;
                    for(int i=yy;i<40;i++)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy+1));}
                }

            }
            //8
            if(temp_flag==1)
            {

            if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      &&y_point<yy)//d
                {
                    temp_flag=0;
                    for(int i=yy;i>0;i--)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy-1));}
                }
            else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      &&y_point>yy)//c
                {
                    temp_flag=0;
                    for(int i=yy;i<40;i++)
                    {
                        if(a[xx][i]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift(xx,(yy+1));}
                }
            else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      &&x_point<xx)//b
                {
                    temp_flag=0;
                    for(int i=xx;i>=0;i--)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx-1),yy);}
                }
            else if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      &&x_point>xx)//a
                {
                    temp_flag=0;
                    for(int i=xx;i<20;i++)
                    {
                        if(a[i][yy]==3){temp_flag=1;}
                    }
                    if(temp_flag==0){shift((xx+1),yy);}
                }

            }





            //end
            if(temp_flag==1)
            {
                  if(a[xx+1][yy]!=1&&a[xx+1][yy]!=3      ){shift((xx+1),yy);}
             else if(a[xx-1][yy]!=1&&a[xx-1][yy]!=3      ){shift((xx-1),yy);}
             else if(a[xx][yy+1]!=1&&a[xx][yy+1]!=3      ){shift(xx,(yy+1));}
             else if(a[xx][yy-1]!=1&&a[xx][yy-1]!=3      ){shift(xx,(yy-1));}
             else {dead_flag=1;}
            }



        }

        // colosh
        if (a[xx][yy]==a[x_point][y_point])
        {
            sl++;
            point_finder();
        }
        update();
        Sleep(1000); //----------------------

    }
    cout<< "\n\tGAME OVER"<< "\n\t score : "<<sl;
}
