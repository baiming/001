/*#,,include <stdio.h>
char * mystrcpy (char* a,const char*b)
{   
    int i;
    for (i = 0; a[i] != '\0'; i++) 
    {
       a[i] = b[i];
    }
    return a;
}
int main(int argc, const char *argv[])
{
    char q[4]="qwe";
    char *j="rrr";
    printf("%s\n",mystrcpy(q,j) );
    return 0;
}*/
//-------------------
#include <stdio.h>
int len_h=0;
char *max_ (char *a) 
{   
    int i=0;char* i_max;int w=0;
    for(i= 0;a[i]!= '\0';i++)
   {  
        if(a[i] != a[i+1])
        {   
        if(++w>len_h)
        {
            len_h=w;
            i_max=&a[i+1-len_h];
         }
            w= 0;
        }    
            if(a[i] == a[i+1])
            {   
                w++;
          //      if(++w > len_h)
            //    {
                 
               // len_h= w;
             //   }   
            }    
       
    }      
   
    return i_max;
}   
int main(int argc, const char *argv[])
{
    int p;
    char* a="dddaadfffffdddeeefrfff";
    char *q;
    q=max_(a);
    for (p = 0; p < len_h; p++) 
    {
        printf("%c",*(q+p));
        }
    printf("\n");
    return 0;
}
/*
#include <stdio.h>
int pp_(char * a,char * b)
{
    while(*a||*b)
       {         
           if(*a!=*b)
           break;
        a++;b++;
       } 
       return (int)(*a - *b);
}
int main(int argc, const char *argv[])
{
    char *a="abc";
    char *b="adc";
    printf("%d\n",pp_(a,b));
    return 0;
}*/
//---------------------
/*#include <stdio.h>
#include <stdlib.h>
struct x{char a[5];int d;int f;int g;int h;};
int main(int argc, const char *argv[])
{
    int i;
    //struct x x0;
    struct x *x1;
    x1= (struct x*) malloc(21);
    x1->a[0]=0;
    x1->a[1]=1;
    x1->a[2]=2;
    x1->a[3]=3;
    x1->d=4;
    x1->f=5;
    x1->g=6;
    x1->h=7;
    for(i=0;i<4;i++)
     {
        printf("%d",x1->a[i]);
     }
   
     printf("%d%d%d%d\n",(*x1).d,(*x1).f,(*x1).g,(*x1).h);
     
    return 0;
}*/
