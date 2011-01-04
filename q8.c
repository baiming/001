#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu {
int id;char name[20];float chi;float mas;float pi;struct stu *next;};
struct stu * tt_1(struct stu*k,FILE*s ,int l)
{
    struct stu*p;
    int i=0;
    p=malloc(sizeof(int)*100);
    fscanf(s," %d: %d %5s %5f   %5f    %5f\n",&l,&p->id,p->name,&p->chi,&p->mas,&p->pi);
    fprintf(stdout," %d: %d %5s %5.1f   %5.1f    %5.1f\n",l,p->id,p->name,p->chi,p->mas,p->pi);
    i++;
    p->next=k;
    return p;
}    
/*struct stu * add(int a,char b,float c,float d,float e)
{
    struct stu*p;
    //int i=0;
    p=malloc(sizeof(int)*100);
    p->id=id;
    trycpy(p->name,name);
    p->chi=chi;
    p->mas=mas;
    p->pi=pi;
    //fscanf(s," %d: %d %5s %5f   %5f    %5f\n",l,&p->id,p->name,&p->chi,&p->mas,&p->pi);
    //fprintf(stdout," %d: %d %5s %5.1f   %5.1f    %5.1f\n",l[i],p->id,p->name,p->chi,p->mas,p->pi);
    //i++;
    p->next=NULL;
    return p;
} */   
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
 struct stu* bb(struct stu* b,struct stu* k)
 {
     struct stu*i,*j;
     i=b;
     if(k->pi < i->pi)
     {
         k->next=i;
         return k;
     }
     j=i;i=i->next;
     while(i!=NULL)
     {
        if(k->pi < i->pi)
        {
            break;
        }
        else
            j=i;i=i->next;
     }
     if(i)
     {
        k->next=i;
        j->next=k;
     }
        else
     {
        k->next=NULL;
        j->next=k;
     }
     return b;
 }
 struct stu* aa(struct stu*t0)
 {
     struct stu*b,*c,*d,*q;int r;
     c=t0->next;
     t0->next=NULL;
     printf("%d\n",t0->id);
     while(c!=NULL)
     {
        d=c->next;
        t0=bb(t0,c);
        c=d;
     }  
            q=t0;
            r=1;
            while(q != NULL)
            {
                printf(" %d: %d %5s %5.1f   %5.1f   %5.1f\n",r,q->id,q->name,q->chi,q->mas,q->pi);
                r++;
                q=q->next;
            }
 }
 int main(int argc, const char *argv[])
 {
    int w,a;int t=7;
    char b;
    float c,d,e,f;
    int cc=7;
    struct stu*q,*t0,*p;
    FILE*s;
    int i=0;int j=0;int h=1;
    struct stu *x;
    struct stu m[]={
    {1,"ddd",20.0,30.0,25.0},
    {2,"fff",20.0,30.0,25.0},
    {3,"aaa",10.0,20.0,15.0},
    {4,"bbb",11.0,12.0,12.0},
    {5,"eee",0.0,0.0,0.0},
    {6,"www",12.0,12.0,12.0},
    {7,"xyz",20.0,30.0,25.0}};
    int r=1;
    while(1)
    {
        printf("Please select the option:\n");
        printf("1.Display all student's info\n");
        printf("2.Sort by average\n");
        printf("3.Insert a new info\n");
        printf("4.Delete a record\n");
        printf("5.Quit\n");
        printf("Please input your choise:");
        scanf("%d",&w);
        getchar();
        printf("seq ID NAME CHGRADE MATHGRADE AVERAGE\n");
        printf("------------------------------------------\n");
        s=fopen("1.txt","w");
        for(i=0;i<t;i++)
            {
              fprintf(s," %d: %d %5s %5.1f   %5.1f    %5.1f\n",r,m[i].id,m[i].name,m[i].chi,m[i].mas,m[i].pi); 
              r++;
            };
            fclose(s);
            s=fopen("1.txt","r");
            i=0;
         if(w==1)  
         { 
            p=tt_1(NULL,s,r);
            for(i=0;i<t-1;i++)
                {
                    p=tt_1(p,s,r);
                }
            printf("-----------------------------------------\n");
         }   
        if(w==2)
        {
            t0=p;
            t0=aa(t0);
        }
        if(w==3)
        {
            fclose(s);
            struct stu *x;
            x=malloc(sizeof(int)*100);
            printf("Please input the new info(ID name chgrade mathgrade average):\n");
            printf("ID shuould more than 7\n");
            s=fopen("1.txt","a");
            fscanf(stdout," %d %5s %5.1f   %5.1f   %5.1f",&x->id,x->name,&x->chi,&x->mas,&x->pi);
            fprintf(s," %d %5s %5.1f   %5.1f   %5.1f",x->id,x->name,x->chi,x->mas,x->pi);
            //fflush(s);
        }
        if(w==4)
        {
            printf("please choose the way:\n");
            printf("1.Delete by ID\n");
            printf("2.Delete by name\n");
            printf("Exit\n");
            printf("Your choice:");
            scanf("%d\n",&a);
            printf("Your should choose the number include 1-8:\n");
            scanf("%d\n",&b);
            printf("selunm = %d\n",b);
        }
        if(w==5)
        break;
    }
    return 0;
 }

