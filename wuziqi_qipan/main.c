
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "main.h"
void create_scr_fb(void)
{
    int fd;
    struct fb_var_screeninfo fb_var;
    u32_t *p=NULL;

    fd=open("/dev/fb0",O_RDWR);
    if(fd<0)
    {
        perror("open");
        exit(1);
    }
    if(ioctl(fd,FBIOGET_VSCREENINFO,&fb_var)<0)
    {
        perror("ioctl");
        exit(1);
    }
    fb_v.w=fb_var.xres;  
    fb_v.h=fb_var.yres;  
    fb_v.bpp=fb_var.bits_per_pixel; 
    printf("w = %d\th = %d\tbpp = %d\n",fb_v.w,fb_v.h,fb_v.bpp);
    p = mmap(NULL,fb_v.w*fb_v.h*fb_v.bpp/8,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
    if(p == MAP_FAILED)
    {
        perror("map");
        exit(1);
    }
    *(p)=0x00ff0000;
    fb_v.fb_mem = p;
//    close(fd);
}

int fb_one_pixel(int x,int y,u32_t color)
{
    u32_t *p = fb_v.fb_mem;

    p[x+y*fb_v.w] = color;
    return 0;
}

void scan_scr(void)
{
    int i = 0;
    int j = 0;
    int w = 30;
    u32_t *p = fb_v.fb_mem;
    for(i=1;i<26;i++)
    { 
        for(j=0; j < (fb_v.w-124); j++)
        {
            p[w*i*fb_v.w+j] = 0x000000ff;    // da yin yi hang
        }
    }



    for(j=1;j<32;j++)
    {
        for(i=0; i < fb_v.h-48; i++)
        {
            
            p[j*w+i*fb_v.w]= 0x00ff0000;  // da yin yi lie
            //usleep(20);
        }
    }



        /*for(i=0; i<fb_v.h; i++)       //xu  xian
        {
            p[i*fb_v.h+400]= 0x00ff0000;
        //}*/
        //}
         
}
int main(int argc, const char *argv[])
{
    int i=0;
    int kk = 0;
    create_scr_fb();

    //fb_circle(500, 350, 200, 0x000000ff);
    //scan_scr();
  /* for(i=0;i<910;i++)
    {
        fb_line(80+i,20,80+i,750,0x00ac899c);  //hua xian han shu
        //usleep(50);
    }*/
    while(kk == 0)
    {
    for(i=0;i<910;i++)
    {
        fb_line(80+i,20,80+i,750,0x00ac899c);  //hua xian han shu
     //   usleep(50);
    }
        print_board();
        kk = mouse_doing();
    }    

   /*while(1)
   {
    draw_cursor(550,333);
    restore_shape(100,40);
    //sleep(1);
    //draw_cursor(100,222);
    //restore_shape(100,222);
   }*/

    return 0;
}
