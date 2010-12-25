/*#include <stdio.h>
struct stu_ {
int id;int chi;char name[200];};
void suap_ (struct stu_*a, struct stu_*b)
{   
    struct stu_ q;
    q=*a;
    *a=*b;
    *b=q;

}
int main(int argc, const char *argv[])
{
    struct stu_ a={0,88,"zzz"};
    struct stu_ b={1,99,"ccc"};
    suap_(&a,&b);
    printf("%d %d %s\n",a.id,a.chi,a.name);
    //printf("%d\n",b[0].id);
    return 0;
}*/
//------------------------------
/*#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
   int p;int q=0; int j ;int* i;
    i=malloc(sizeof(int)*5);
  int num=5;
  while(1)
    {  
        if(q>=num)
        {
        num+=5;    
        i=realloc(i,sizeof(int)*num);
        }
        scanf("%d",&i[q]);    
        q++;
        if(i[q-1]==-1)
        break;
    }
    printf("yes\n");
    for(p=0;p<q-1;p++)
    printf("%d ",i[p]);
    printf("\n");
    free(i);
    i=NULL;
    return 0;
}*/
-----------------------------
/*#include <stdio.h>
typedef struct{
char b;int a;}qq;
int main(int argc, const char *argv[])
{
    qq p;
    printf("%d\n",sizeof(p));
    return 0;
}*/
//----------------------------------
/*#include <stdio.h>
struct com{
char * comand[20];char* in;char * out;};
struct com q_0;
void sha (char* a)
{
    int n=0;
    int i;
    char *p=a;
    while(*p!='\0')    
{
            if(*p=='>')
            {
                p++;
                while(*(p++)==' ');
                q_0.out=--p;
            }
            if(*p=='<')
            {
                p++;
                while(*p++==' ');
                q_0.in=--p;
                
            }
                if(*p==' ')
            {
                *p='\0';
                 p++;
                 continue;
            }
            if( *p!=' ' && (*(p-1)=='\0' || p==a))
           {
                q_0.comand[n++]=p;
                p++;
                continue;
           }
                p++;
}
}
void ppp()
{
    char*p;
    int i;
    if(q_0.in||q_0.out)
    printf("%s %s",q_0.in,q_0.out);
    for(i=0;i<5;i++)
    {
         p=q_0.comand[i];
         if(i==0)
         printf("comand:%s\n",p);
         else
        {
         printf("canshu:");
         printf("%s ",p);
        }
    }
}
int main(int argc, const char *argv[])
{
    char a[255];
    fgets(a,255,stdin);
    sha(a);
    ppp();
    return 0;
}*/
