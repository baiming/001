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
    printf("%d\n",a.id);
    //printf("%d\n",b[0].id);
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
   int p;int q=0; int j ;int* i;
    i=malloc(20);
    //i= realloc(i,80);
    while(1)
    {  
        if(q>=5)
        i=realloc(i,40);
        scanf("%d",&i[q]);    
        q++;
        if(i[q-1]==-1)
        break;
    }
    printf("yes\n");
    for(p=0;p<q-1 ;p++)
    printf("%d ",*(i+p));
    printf("\n");
    free(i);
    i=NULL;
    return 0;
}*/
