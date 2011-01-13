#include <stdio.h>
#include "main.h"

#define    STARTING_X 100
#define    STARTING_Y 40
#define    SPACE 30
/*void yuan (int a,int b, int r, int color)
{
    int i,j;
    int x=a;
    int y=b;
    for(i=0;i<10;i++)
    {
        x=a+i;
        for(j=0;j<10;j++)
        {
            if((x*x + y*y) > r*r)break;
            y=b+j;
            fb_one_pixel(x, y,color);
        }
    }

}*/
/*void circle(int centerx, int centery, int radius, int color, int type)
{
    int x = 0;
    int y = radius;
    int delta = 2*(1-radius);
    int direction;
    while (y >= 0) {
    if (!type) {
    fb_one_pixel(centerx+x, centery+y, color);
    fb_one_pixel(centerx-x, centery+y, color);
    fb_one_pixel (centerx-x, centery-y, color);
    fb_one_pixel(centerx+x, centery-y, color);
     }
else {
    fb_line(centerx+x, centery+y, centerx+x, centery-y, 0x00ffffff);
    fb_line(centerx-x, centery+y, centerx-x, centery-y, 0x00ffffff);
     }
    if (delta < 0) {
        if ((2*(delta+y)-1) < 0) {
            direction = 1;
               }
               else {
                    direction = 2;
                    }
                   }
             else if(delta > 0) {
            if ((2*(delta-x)-1) <= 0) {
                        direction = 2;
                               }
            else {
                  direction = 3;
                 }
                 }
         else {
            direction=2;
              }
        switch(direction) {
                            case 1:
                               x++;
                              delta += (2*x+1);
                            break;
                            case 2:
                                      x++;
                                     y--;
                                delta += 2*(x-y+1);
                                   break; 
                            case 3:
                                    y--;
                                   delta += (-2*y+1);
                              break;
                          }
                 }
} */

int paduan(int x,int y,int p)
{
    int w1;int w2;
    if(p==0)
    {
        w1=x;
        w2=y;
        return x;
    }
    if(p>0)
    {
        if(w1==x && w2==y)
        return 0;
        w1=x;
        w2=y;
        return x;
    }    

}



void print_one_chess (int mx,int my,int q)
{
    int i=0;
    int c=0;
    int x,y;
    int p=q;
    int t;
            x=STARTING_X;
            y=STARTING_Y;
            for(i=0;i<24;i++)
            {
                for(c=0;c<31;c++)
                {    
                    x=STARTING_X + 30*c;
                    if(c==30)
                    {
                        y+=30;
                    }
                    
                    if((abs(mx-x)<15) && (abs(my-y)<15))
                    { 
                            
                       /* if(w1==x && w2==y)
                        break;
                        w1=x;
                        w2=y;*/
                        //t=paduan(x,y,q);
                        //if(t==0)break;
                        mx=x;
                        my=y;
                        if(q%2==0)
                        {
                           //  yuan(a,b,10,0x00ffffff);
                           //fb_one_pixel(mx,my,0x000000ff);
                         /*   for(h=10.0;h>0;h-=0.01)
                            {
                                circle(a, b,h,0x00ffffff, 0);
                            }*/
                            fb_circle(mx,my,13,0x00ffffff);
                        } 
                        if(q%2==1)
                        {
                           // yuan(a,b,10,0x00000000);
                           //fb_one_pixel(a,b,0x000000ff);
                            /*for(h=10.0;h>0;h-=0.01)
                            {
                                circle(a, b,h,0x00000000, 0);
                            }*/
                            fb_circle(mx,my,13,0x00000000);
                        }
                        //q++;
                        break;
                    } 
                 }

                if((abs(mx-x)<15) && (abs(my-y)<15))
                break;
             } 

            //}    
}  

void print_board(void)  //ge zi
{
    float h=10.0;
    int i=0;
    int c=0;
    //int a,b
    int q;
    int d=1;
    int x,y,w1,w2;
    for(i=0; i<P_NUM; i++)
    {
        fb_line(STARTING_X, STARTING_Y+i*SPACE, STARTING_X+(V_NUM-1)*SPACE, STARTING_Y+i*SPACE, 0x008b6904);

    }
    for(i=0; i<V_NUM; i++)
    {
        fb_line(STARTING_X+i*SPACE, STARTING_Y, STARTING_X+i*SPACE, STARTING_Y+(P_NUM-1)*SPACE, 0x008b6904);

    }
    
    //scanf("%d",&d);
    //getchar();

   /* while(1)                         // que ren qi zi zuo biao 
    {
        //if(d==0) break;
        if(d==1)
        {
            x=STARTING_X;
            y=STARTING_Y;
            printf("star\n");
            //scanf("%d %d",&a,&b);
            //getchar();
            //if(a==0)
            //break;
            for(i=0;i<24;i++)
            {
                for(c=0;c<31;c++)
                {    
                    x=STARTING_X + 30*c;
                    if(c==30)
                    {
                        y+=30;
                    }
                    
                    if((abs(mx-x)<15) && (abs(my-y)<15))
                    { 
                            
                        if(w1==x && w2==y)
                        break;
                        w1=x;
                        w2=y;
                        mx=x;
                        my=y;
                        if(q%2==0)
                        {
                           //  yuan(a,b,10,0x00ffffff);
                           fb_one_pixel(mx,my,0x000000ff);
    //for(h=10.0;h>0;h-=0.01)
    //{
    //circle(a, b,h,0x00ffffff, 0);
    //}
                            fb_circle(mx,my,13,0x00ffffff);
                        } 
                        if(q%2==1)
                        {
                           // yuan(a,b,10,0x00000000);
                           //fb_one_pixel(a,b,0x000000ff);
                           //
                           //
                           //
                           //for(h=10.0;h>0;h-=0.01)
                           //{
                           //circle(a, b,h,0x00000000, 0);
                           //}
                           //
                           //
                           //
                            //fb_circle(a,b,13,0x00000000);
                            
                        }
                        q++;
                        break;
                    } 
                 }

                    if((abs(mx-x)<15) && (abs(my-y)<15))
                    break;
             } 

         }    
     }  */

}
