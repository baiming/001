#include "main.h"
void swap(int *a, int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int fb_line (int x1, int y1,int x2, int y2, u32_t color)    //hua xian
{
    int dx = x2-x1;
    int dy = y2-y1;
    int inc = ((dx*dy>0) ? 1 : -1);
    int p=0;
    if(abs(dx) > abs(dy))
    {
        if(dx < 0)
        {   
            swap(&x1 ,&x2);
            swap(&y1,&y2);
            dx = -dx;
            dy = -dy;
        }
        dy = abs(dy);
        p = 2*dy-dx;
        while(x1 <= x2)
        {
            fb_one_pixel(x1, y1, color);     
            x1++;
            if(p<0)
            {
                p += 2*dy;
            }
            else
            {
                p += 2*(dy-dx);
                y1+=inc;
            }
    
        }   

    }
    else
    {
      
        if(dy < 0)
        {   
            swap(&x1 ,&x2);
            swap(&y1,&y2);
            dx = -dx;
            dy = -dy;
        }
        dx = abs(dx);
        p = 2*dx-dy;
        while(y1 <= y2)
        {
            fb_one_pixel(x1, y1, color);
            y1++;
            if(p<0)
            {
                p += 2*dx;
            }
            else
            {
                p += 2*(dx-dy);
                x1+=inc;
            }
    
        }   
    
    
    }
    return 0;
}

int fb_circle(int x0, int y0, int r, u32_t color)    //  hua yuan
{
    int x = 0;
    int y = r;
    
    int p = 3-2*r;

    while(x <= y)
    {
/*#if 0
        fb_one_pixel(x0+x, y0+y, color);         //hua  kong xin  huan  
        fb_one_pixel(x0+y, y0+x, color);
        fb_one_pixel(x0+x, y0-y, color);
        fb_one_pixel(x0+y, y0-x, color);
        fb_one_pixel(x0-x, y0+y, color);
        fb_one_pixel(x0-y, y0+x, color);
        fb_one_pixel(x0-x, y0-y, color);
        fb_one_pixel(x0-y, y0-x, color);
        
        
        

        fb_line(x0, y0,x0+x,y0+y, color);         //bu wan zheng de  shi xin huan
        fb_line(x0, y0,x0+y,y0+x, color);         
        fb_line(x0, y0,x0+x,y0-y, color);         
        fb_line(x0, y0,x0+y,y0-x, color);         
        fb_line(x0, y0,x0-x,y0+y, color);         
        fb_line(x0, y0,x0-y,y0+x, color);         
        fb_line(x0, y0,x0-x,y0-y, color);         
        fb_line(x0, y0,x0-y,y0-x, color);   */   


//#endif
        fb_line(x0+x, y0+y, x0-x, y0+y, color);   // shi xin yuan
        fb_line(x0+y, y0+x, x0-y, y0+x, color);
        fb_line(x0+y, y0-x, x0-y, y0-x, color);
        fb_line(x0+x, y0-y, x0-x, y0-y, color);
        
        if(p < 0)
        {
            p += 4*x+6;
        }
        else
        {
            p += 4*(x-y) + 10;
            y--;
        }
        x++;
    
    }
    return 0;
}
