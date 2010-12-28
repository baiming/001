#include <stdio.h>
#include <stdlib.h>
struct stu{
int item; struct stu *next;};
struct stu* kk_ (struct stu*a,int item)
{
    struct stu *p=malloc(sizeof(struct stu));
    p->item=item;
    p->next=a;
    return p;
}
void pr(struct stu*k,int n)
{
    struct stu*p,*i;
    p=k;
    int j=0;
    while(1){
        //printf("%d\n",p->item)
    j++;
    p=p->next;
    if(j==n)
    {
        printf("%d\n",p->next->item);
        j=0;
        i=p->next;
        p->next=p->next->next;
        free(i);
    }
    if(p==p->next)
    break;
    }
}
int main(int argc, const char *argv[])
{
    struct stu *m,*q;
    int i;
    m= malloc(sizeof(struct stu));
    m->item=1;
    q=m;
    q->next=q;
    for(i=2;i<11;i++){
       q=q->next=kk_(q->next,i);
    }
    pr(q,2);
    return 0;
}
