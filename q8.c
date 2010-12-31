#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu {
char sep[3];int id;char name[20];float chi;float mas;float pi;struct stu *next;};
struct stu * tt_1(struct stu*k,FILE*s )
{
    struct stu*p;
    p=malloc(sizeof(int)*100);
    fscanf(s," %s %d %5s %5f   %5f    %5f\n",p->sep,&p->id,p->name,&p->chi,&p->mas,&p->pi);
    fprintf(stdout," %s %d %5s %5.1f   %5.1f    %5.1f\n",p->sep,p->id,p->name,p->chi,p->mas,p->pi);
    p->next=k;
    return p;
}
/*struct stu *t0(struct stu*l)
{    struct stu *k,*h;
    h=l;
    //k=malloc(sizeof(int)*20);
    while(l->next!=NULL){
    if(l->pi > l->next->pi)
    {
    }
    if(l->pi < l->next->pi)
    
    {
        
        if(l->pi - h->pi>0)
        {   
           l->next=h;
            
        }
        else{
        while(l->pi - h->next->pi<0)
        {
            h=h->next;
         
        }
            
            l->next=h->next;h->next=l;

        }   
    }   
    l=l->next;
    }
//k->next=NULL;
    return h;
    }*/
struct stu* bb(struct stu* b,struct stu* c)
{
    struct stu*i,*j;
    if(c->pi > b->pi)
    {
        c->next=b;
        return c;
    }
    b->next=c;
    b=b->next;
    if(b->pi < b->next->pi)
    {
        if
    
    }
}
struct stu* aa(struct stu*t0)
{
    struct stu*b,*c,*d;
    c=t0->next;
    t0->next=NULL;
    t0=bb(t0,c)
}
int main(int argc, const char *argv[])
{
    int w;
    int cc=7;
    struct stu*q,*to,*p;
    FILE*s;
    int i=0;int j=0;
    struct stu *x;
    struct stu m[]={
    {"1:",1,"ddd",20.0,30.0,25.0},
    {"2:",2,"fff",20.0,30.0,25.0},
    {"3:",3,"aaa",10.0,20.0,15.0},
    {"4:",4,"bbb",11.0,12.0,12.0},
    {"5:",5,"eee",0.0,0.0,0.0},
    {"6:",6,"www",12.0,12.0,12.0},
    {"7:",7,"xyz",20.0,30.0,25.0}};
    printf("Please select the option:\n");
    printf("1.Display all student's info\n");
    printf("2.Sort by average\n");
    printf("3.Insert a new info\n");
    printf("4.Delete a record\n");
    printf("5.Quit\n");
    printf("Please input your choise:");
    scanf("%d",&w);
    printf("seq ID NAME CHGRADE MATHGRADE AVERAGE\n");
    printf("------------------------------------------\n");
    if(w==1)
    {
        s=fopen("1.txt","w");
        for(i=0;i<7;i++)
        { 
            fprintf(s," %s %d %5s %5.1f   %5.1f    %5.1f\n",m[i].sep,m[i].id,m[i].name,m[i].chi,m[i].mas,m[i].pi);
        } 
        fclose(s);
        s=fopen("1.txt","r");
        p=tt_1(NULL,s);
        for(i=0;i<6;i++)
        {
            p=tt_1(p,s);
        }
    printf("-----------------------------------------\n");
    }   
        
    /*        t0=p;
        t0=aa(t0);
    while(t0!=NULL)
    {   
        printf("%d\n",t0->pi);
        t0=t0->next;
    }*/
    return 0;
}
