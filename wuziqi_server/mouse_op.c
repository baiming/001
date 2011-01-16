#include "main.h"
#define C_WIDTH 10
#define C_HEIGHT 17
#define T__ 0X0
#define BORD 0X0
#define X__ 0XFFFF

#define SPACE     30
#define STARTING_X   100
#define STARTING_Y   40
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
u32_t color_choice;
char w = 1 ;
char board[V_NUM*P_NUM];

/*int choose_color(int x ,int y)
{
    if((x>=20) && (x>=60))
    {
        if((y>=40) && (y<=80))
        {
            color_choice = 0x000000ff;
            who = 1;
        }
        else if((y>=120) && (y<=160))
        {
            color_choice = 0x00ff0000;
            who = 2;
        }
    
    }

    return 0;
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
            if(cursor_pixel[j+i*C_WIDTH] == 0xFFFF) 
            {
                fb_one_pixel(x+j, y+i, cursor_pixel[j+i*C_WIDTH]);
            }    
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

int chess_count(int x, int y,int w)
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
    board[i+j*V_NUM] = w;
   
    return 0;


}



int check_five(int x, int y)
{
    int i = 0;
    int j =0;
    char counter = 0;
    char storage = 0;
    char nx = 0;
    char ny = 0;
    char n_x[4]= {0,1,1,1};
    char n_y[4]= {1,0,1,-1};

    storage = board[x+y*V_NUM];
    if(storage == 0)
    {
        return 0;
    }
    for(j=0;j<4;j++)
    {
        counter = 1;
        nx = x;
        ny = y;
        for(i=1; i<5; i++)
        {
            nx += n_x[j];
            ny += n_y[j];
            if(board[nx+ny*V_NUM] == storage)
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
               printf("%d won!\n", w-1);
                return 1;
            
            }
        
        }
    
    }

    return 0;

}

int mouse_doing(void)                // zheng chang hua qi zi (dan  ji)
{
    m_event mevent;
    int kkk,a;
    int p = 0;
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
                case 1 :
                         w= print_one_chess(mx, my,p) ;
                         save_shape(mx ,my);
                         chess_count(mx,my,w);
                         a = check_all();
                         if(a == 1)
                         break;
                         p++;
                         break;
                case 2 : break;
                case 4 : break;
                default: break;
            
            }
            if(a != 1)
            draw_cursor(mx ,my);
          if(a == 1)
            {
                bzero(&board,sizeof(board));
                printf("go: 0   exit: 1\n");
                scanf("%d",&kkk);
                break;
            }
        }
        usleep(1000);
    }
    if(kkk == 1) close(fd);  
    return kkk;
}

int mouse_doing1(int x,int y)             //wang luo  hua qi zi  (zuo wei ke hu duan)
{
    printf("%d\n",x);
    printf("%d\n",y);
    m_event mevent;
    int kkk;
    int a;
    int p = 0;
    int fd;
    int k1,k2;
    k1=x*30+100;
    k2=y*30+40;
                         w= print_one1_chess(k1,k2);
                         p++;
                         save_shape(k1 ,k2);
                         chess_count(k1,k2,w);
                         a = check_all();
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
            if(my>= (fb_v.h-C_HEIGHT))
            {
                my = (fb_v.h-C_HEIGHT);
            
            }
            switch(mevent.button)
            {
                case 1 :
                         pp->x = (mx - 100)/30;
                         pp->y = (my - 40)/30;
                         w= print_one_chess(mx,my,p);
                         save_shape(mx ,my);
                         chess_count(mx,my,w);
                         a = check_all();
                         if(a == 1)
                         break;
                         p++;
                         
	                  	 sendto(server_sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client, client_len);
                         break;
                case 2 : break;
                case 4 : break;
                default: break;
            
            }
            if(a != 1)
            draw_cursor(mx ,my);
            if(a == 1)
            {
                bzero(&board,sizeof(board));
                printf("go: 0   exit: 1\n");
                scanf("%d",&kkk);
                break;
            }
        }
        usleep(1000);
        if(kkk == 1) close(fd);  
        if(p%2 == 0) 
        {
            restore_shape(mx,my);
            break;
        }       
    }
    return 0;
}



