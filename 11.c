#include <stdio.h>
int add_kk (int a,int b);
int main(int argc, const char *argv[])
{
    int x=0;
    int y=2;
    add_kk(x,y);
    return 0;
   
}
int add_kk (int a,int b)
{
    if(a==0)
    {
    printf("a is 0\n");
    return 0;
                     
    }
    return a + b;

}
