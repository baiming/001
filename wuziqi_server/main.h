
#ifndef _MAIN_H
#define _MAIN_H

#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define    V_NUM 30
#define    P_NUM 24
#define BUFFER_SIZE		12
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
typedef struct{
char dest; 
char source;
char type;
char len;
int x;
int y;}msg_t;

extern char buffer[BUFFER_SIZE];
extern  socklen_t client_len;
extern	int server_sock;
extern	struct sockaddr_in server,client;
extern	struct in_addr in;
extern  msg_t *pp;
extern int print_one1_chess (int mx,int my);
extern void create_scr_fb(void);
extern int mouse_doing1(int x,int y);
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

#endif
