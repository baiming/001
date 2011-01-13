#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
#define C_WIDTH 10
#define C_HEIGHT 17
#define T__ 0X0
#define BORD 0X0
#define X__ 0XFFFF

#define C_WIDTH   10
#define C_HEIGHT  17

#define SPACE     30
#define STARTING_X   100
#define STARTING_Y   40

//exturn
//int mouse_doing(void)
//{
    static u32_t cursor_pixel[C_WIDTH *C_HEIGHT]={
    BORD, T__,T__,T__,T__,T__,T__,T__,T__,T__,
    BORD, BORD,T__,T__,T__,T__,T__,T__,T__,T__,
    BORD, X__,BORD,T__,T__,T__,T__,T__,T__,T__,
    BORD, X__,X__,BORD,T__,T__,T__,T__,T__,T__,
    BORD, X__,X__,X__,BORD,T__,T__,T__,T__,T__,
    BORD, X__,X__,X__,X__,BORD,T__,T__,T__,T__,
    BORD, X__,X__,X__,X__,X__,BORD,T__,T__,T__,
    BORD, X__,X__,X__,X__,X__,X__,BORD,T__,T__,
    BORD, X__,X__,X__,X__,X__,X__,X__,BORD,T__,
    BORD, X__,X__,X__,X__,X__,X__,X__,X__,BORD,
    BORD, X__,X__,X__,X__,X__,BORD,BORD,BORD,BORD,
    BORD, X__,X__,BORD,X__,X__,BORD,T__,T__,T__,
    BORD, X__,BORD,T__,BORD,X__,X__,BORD,T__,T__,
    BORD, BORD,T__,T__,BORD,X__,X__,BORD,T__,T__,
    T__, T__,T__,T__,T__,BORD,X__,X__,BORD,T__,
    T__, T__,T__,T__,T__,BORD,X__,X__,BORD,T__,
    T__, T__,T__,T__,T__,T__,BORD,BORD,T__,T__

};
static u32_t shape_save[C_WIDTH*C_HEIGHT];

char who = 1;
char board[V_NUM*P_NUM];
/*int paduan(int x,int y,int p)
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

}*/

int save_shape(int x, int y)
{
    int i = 0;
    int j = 0;
    u32_t *p = fb_v.fb_mem;

    for(i=0; i<C_HEIGHT; i++)
    {
        for(j=0; j<C_WIDTH; j++)
        {
            shape_save[j+i*C_WIDTH] = p[x+j+(y+i)*fb_v.w];
        }
    }
    return 0;
}
int restore_shape(int x, int y)
{
    int i = 0;
    int j = 0;

    for(i=0; i<C_HEIGHT; i++)
    {
        for(j=0; j<C_WIDTH; j++)
        {
            fb_one_pixel(x+j,y+i, shape_save[j+i*C_WIDTH]);
        }
    }
    return 0;
    

}

int draw_cursor(int x, int y)
{
    int i = 0;
    int j = 0;
    save_shape(x ,y);
    for(i=0; i<C_HEIGHT; i++)
    {
        for(j=0; j<C_WIDTH; j++)
        {
            fb_one_pixel(x+j, y+i, cursor_pixel[j+i*C_WIDTH]);
        }
    }
    return 0;

}

int get_m_info(int fd,m_event *event)
{
    char buf[8] = {0};    
    int n;

    n = read (fd, buf ,8);
    if(n <= 0)
    {
        return 0;
    }
    event->button =(buf[0]&0x07);
    event->dx = buf[1];
    event->dy = -buf[2];
    event->dz = buf[3];
    return n;
}

int chess_count(int x, int y)
{
    int i = x;
    int j = y;

    i = (i-STARTING_X)/SPACE;
    j = (j-STARTING_Y)/SPACE;

    if(((x-STARTING_X)%SPACE) > (SPACE/2))
    {
        i++;
    }
    if(((y-STARTING_Y)%SPACE) > (SPACE/2))
    {
        j++;
    }
    board[i+j*V_NUM] = who;
   
    return 0;


}



int check_five(int x, int y)
{
    int i = 0;
    char counter = 0;
    char storage = 0;

    storage = board[x+y*V_NUM];
    if(storage == 0)
    {
        return 0;
    }
    counter = 1;

    for(i =1; i<5; i++)
    {
        if(board[x+i+(y+i)*V_NUM] == storage)
        {
            counter++;
        }
        else
        {
            break;
        }
    }
    if(counter == 5)
    {
        return storage;
    }
    return 0;

}

int check_all(void)
{
    int i = 0;
    int j = 0;
    
    for(i=0; i<P_NUM; i++)
    {
        for(j=0; j<V_NUM; j++ )
        {
            if(check_five(i,j) != 0)
            {
                printf("%d won!\n", who);
                return 1;
            
            }
        
        }
    
    }

    return 0;

}

int mouse_doing(void)
{
    m_event mevent;
    int w1,w2;
    int p=0;
    int fd;
    int mx = 512;
    int my = 384;
    fd = open("/dev/input/mice",O_RDWR|O_NONBLOCK);
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    draw_cursor(mx, my);
    
    while(1)
    {
        if(get_m_info(fd, &mevent) > 0)
        {
            restore_shape(mx ,my);

            mx += mevent.dx;
            my += mevent.dy;

            mx = ((mx >= 0) ? mx : 0);
            my = ((my >= 0) ? my : 0);
            if(mx >= (fb_v.w-C_WIDTH))
            {
                mx = (fb_v.w-C_WIDTH);
            
            }
            if(my >= (fb_v.h-C_HEIGHT))
            {
                my = (fb_v.h-C_HEIGHT);
            
            }
            switch(mevent.button)
            {
                case 1 : print_one_chess(mx, my,p);
                         save_shape(mx ,my);
                         chess_count(mx,my);
                         check_all();
                         //p++;
                         break;
                case 2 : break;
                case 4 : break;
                default: break;
            
            }
            draw_cursor(mx ,my);


        }
        usleep(1000);

    
    }




return 0;
}



