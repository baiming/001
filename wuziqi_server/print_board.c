#include "main.h"
#define    STARTING_X 100
#define    STARTING_Y 40
#define    SPACE 30
 char w;


int print_one_chess (int mx,int my,int q)
{
    int i=0;
    int c=0;
    int x,y;
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
                            
                        mx=x;
                        my=y;
                        if(q%2==0)
                        {
                            fb_circle(mx,my,13,0x00ffffff);
                        } 
                        if(q%2==1)
                        {
                            fb_circle(mx,my,13,0x00000000);
                        }
                        break;
                    } 
                 }

                if((abs(mx-x)<15) && (abs(my-y)<15))
                break;
             } 

            w = q%2;
            return w+1;   
}  
int print_one1_chess (int k1,int k2)
{
    //if(q%2==0)
    //{
    //circle(a, b,h,0x00ffffff, 0);
                            
                            fb_circle(k1,k2,13,0x00ffffff);
    //} 
   //if(q%2==1)
   //{
   //fb_one_pixel(a,b,0x000000ff);
            
   //fb_circle(k1,k2,13,0x00000000);
   //}
            return 0;  

}  

void print_board(void)  //ge zi
{
    int i=0;
    for(i=0; i<P_NUM; i++)
    {
        fb_line(STARTING_X, STARTING_Y+i*SPACE, STARTING_X+(V_NUM-1)*SPACE, STARTING_Y+i*SPACE, 0x008b6904);

    }
    for(i=0; i<V_NUM; i++)
    {
        fb_line(STARTING_X+i*SPACE, STARTING_Y, STARTING_X+i*SPACE, STARTING_Y+(P_NUM-1)*SPACE, 0x008b6904);

    }
}

