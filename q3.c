#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu{
int id;int chi;struct stu* next;char name[3];
};
struct stu* kk_(struct stu* pro,int id,int chi,char *name)
{
    struct stu* p= (struct stu*) malloc(sizeof(struct stu));
    p->id=id;
    strcpy(p->name,name);
    p->chi=chi;
    p->next=NULL;
    pro->next=p;
    return p;
}
struct stu* del(struct stu* head,int id)
{
    struct stu* p=head,*q;
    if(p->id==id)
    {
        p= p->next;
        free(head);head=NULL;
        return p;
    }    
        while(p->next!=NULL)
        {
            if(p->next->id==id)
            {
                q=p->next;
                p->next=q->next;
                free(q);q=NULL;
            }
                p=p->next;
        }
        return head;
    

}
struct stu* inc(struct stu*k,int id,int chi,char*name)
{
    struct stu *p;
    p=malloc(sizeof(struct stu));
    p->id=id;
    p->chi=chi;
    strcpy(p->name,name);
    p->next=k->next;
    k->next=p;
    return p;
}
void kl (struct stu*p)
{
    struct stu *a=p;
    while(a!=NULL)
    {
        printf("%d %d %s\n",a->id,a->chi,a->name);
        a=a->next;
    }
}
int main(int argc, const char *argv[])
{
    struct stu* m ,*q;
    m=malloc(sizeof(struct stu));
    m->id=1;
    m->chi=99;
    strcpy(m->name,"l");
    q= kk_(m,2,88,"g");
    q= kk_(q,3,83,"f");
    q= kk_(q,4,88,"d");
    q= kk_(q,5,88,"s");
    q= kk_(q,6,88,"z");
    del(m,2);
    //inc(m->next,7,44,"o");
    kl(m);

    return 0;
}
