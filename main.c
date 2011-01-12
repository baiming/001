#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <string.h>
#include <stdio.h>
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
    close(fd);
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

    u32_t *p = fb_v.fb_mem;

    //for(i=0; i<fb_v.h;i++)
    //{
        i = 200;
        for(j=0; j<fb_v.w; j++)
        {
            p[i*fb_v.w+j] = 0x000000ff;    // da yin yi hang
        }
        j=512;
        for(i=0; i<fb_v.h; i++)
        {
            //p[i*fb_v.w+400]= 0x00ff0000;  // da yin yi lie
            fb_one_pixel(j,i,0x00ff0000);
            //usleep(20);
        }
        for(i=0; i<fb_v.h; i++)
        {
            p[i*fb_v.h+400]= 0x00ff0000;
        }
        //}
        
}
int main(int argc, const char *argv[])
{
    int i=0;
    create_scr_fb();
    //scan_scr();
    for(i=0;i<400;i++)
    {
        fb_line(0,10+i,1023,500,0x00ff0000+i);  //hua xian han shu
        usleep(50);
    }    
    return 0;
}
