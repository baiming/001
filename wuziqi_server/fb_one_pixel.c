
#include "main.h"


int fb_one_pixel(int x,int y,u32_t color)
{
    u32_t *p = fb_v.fb_mem;

    p[x+y*fb_v.w] = color;
    return 0;
}
