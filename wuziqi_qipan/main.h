#ifndef _MAIN_H
#define _MAIN_H
#define    V_NUM 30
#define    P_NUM 24
#include <stdio.h>

typedef unsigned int u32_t;
typedef unsigned char u8_t;
typedef struct
{
    int dx;
    int dy;
    int dz;
    int button;

}m_event;
m_event mevent;
typedef struct
{
    int w;
    int h;
    int bpp;
    void *fb_mem;
}v_info_t;
v_info_t fb_v;


extern int paduan(int x,int y,int p);
extern int fb_one_pixel(int x,int y,u32_t color);
extern int fb_line(int x1,int y1,int x2,int y2,u32_t color);
extern void circle(int centerx, int centery, int radius, int color, int type);
extern int fb_circle(int x0, int y0, int r, u32_t color);
extern void print_board(void);
extern int save_shape(int x, int y);
extern int restore_shape(int x, int y);
extern int draw_cursor(int x, int y);
extern int get_m_info(int fd,m_event *event);
extern int print_one_chess (int mx,int my,int p);
extern int mouse_doing(void);
//extern int print_two_chess(int x, int y,int p);
//extern int choose_color(int x ,int y);



#endif
