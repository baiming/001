/*//int ff(void)
//{
char q='*';
printf("%c\n",q);
}
int fff(void)
{
printf("#\n");
}
struct stu_t{
char name[10];int id;int chinese
;int (*f_f)(void);};
int main(int argc, const char *argv[])
{   
    int i;
    struct stu_t arr[5];
    strcpy(arr[0].name,"a");
    arr[0].id=1;
    arr[0].chinese=90;
    arr[0].f_f=ff;
   
    strcpy(arr[1].name,"b");
    arr[1].id=2;
    arr[1].chinese=89;
    arr[1].f_f=fff;
   
    strcpy(arr[2].name,"c");
    arr[2].id=3;
    arr[2].chinese=88;
    arr[2].f_f=ff;
    strcpy(arr[3].name,"d");
    arr[3].id=4;
    arr[3].chinese=87;
    arr[3].f_f=ff;
    strcpy(arr[4].name,"e");
    arr[4].id=5;
    arr[4].chinese=86;
    arr[4].f_f=ff;
    for(i=0;i<5;i++)
   { printf("%s %d %d ",arr[i].name,arr[i].id,arr[i].chinese);
   
       arr[i].f_f();
   
}
    return 0;

    }
//----------------Union--------------------------    
#include <string.h>
#include <stdio.h>
union day{
int a;char b;char c[25];
};
int main(int argc, const char *argv[])
{
    
union day day1;
day1.a=123;
strcpy(day1.c,"abc")
printf("%x\n",day1.a);
    return 0;
}
//-----Pointer to use. Coercion-----------------------
#include <stdio.h>
int main(int argc, const char *argv[])
{
    int *p[6];char b[4]={1,2,3};
    char *q;
    p[1]=&b[0];
    q = (char*)p[1];
    printf("%d\n",*q);
    printf("%d\n",*(q+1));
    printf("%d\n",*(q+2));
    return 0;
}
//------using HuiDiao function played * squar---------
#include <stdio.h>
void kkk (void)
{
    printf("*");

}

void my_1(void(*fun)(void))
{
    int i,j;
    for(j=0;j<5;j++)
   
   {
    
   for(i=0;i<5;i++)
    {
        fun();
    
    }
    printf("\n");
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    my_1(kkk);
    return 0;
}
//---------Array to compare-----------------
#include <stdio.h>
int cmp_int(void * a,void * b)
{
    return *((int *)a) - *((int *)b);
}

int cmp_char (void * a,void * b)
{
    return *((char *)a) - *((char *)b);    


}
void* get_max(void * a,int len,int size, int (*cmp)(void*,void*))

{   
    void * max;
    int i=1;
    max =a;   
    for(i=1;i<10;i++)
    {
    if(cmp(max,a +(i* size))>0)
    {
  }
    else
    {
        max = a + (i*size);
    }
    }
    return max;
    }
int main(int argc, const char *argv[])
{
    int a[10] = {1,4,5,7,8,9,10,2,5};
    char b[10]= {3,5,6,3,6,7,8,7,9};
    void * ret;
    ret = get_max(a,10,4,cmp_int);
    printf("%d\n",*((int *)ret));
    ret = get_max(b,10,1,cmp_char);
    printf("%d\n",*((char *)ret));
    return 0;
    }
//---------*/
#include <stdio.h>
struct p_p{
int id;int out;};
int main(int argc, const char *argv[])
{   
    int i=0;int j=0;int m=0;
    struct p_p p0[10];
    for(i=0;i<10;i++)
    {  
        p0[i].id=i+1;
        p0[i].out=0;
    }
        
    for(i=0;i<10;i++)
    {
            for(; ;)
            {
                if(p0[m].out==0)
                    j++;
     
                if(j==3)
                {
                    p0[m].out=1; 
                     j=0;
                      printf("%d %d\n",p0[m].id,p0[m].out);
                      break;
                }
            
            m++;    
            m=m%10;
           }
            }
    return 0;
}
