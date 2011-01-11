#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu {
int id;char name[20];float chi;float mas;float pi;struct stu *next;};
struct stu *list(struct stu*q,int id,char *name,float chi,float mas, float pi)
{
    q->next=malloc(sizeof(struct stu)*100);
    q=q->next;
    q->next=NULL;
    q->id=id;
    strcpy(q->name,name);
    q->chi=chi;
    q->mas=mas;
    q->pi=pi;
    return q;
}
struct stu * tt_1(FILE*s)
{
    struct stu p,*head,*q;
    head=malloc(sizeof(struct stu)*100);
    fscanf(s," %d %5s %5f   %5f    %5f\n",&p.id,p.name,&p.chi,&p.mas,&p.pi);
    head->id=p.id;
    strcpy(head->name,p.name);
    head->chi=p.chi;
    head->mas=p.mas;
    head->pi=p.pi;
    q=head;
    while(!feof(s))
    {
        fscanf(s," %d %5s %5f   %5f    %5f\n",&p.id,p.name,&p.chi,&p.mas,&p.pi);
        q=list(q,p.id,p.name,p.chi,p.mas,p.pi);
    }
        return head;
}    
struct stu * add(int id,char *name,float chi,float mas,float pi)
{
    struct stu*p;
    p=malloc(sizeof(int)*100);
    p->id=id;
    strcpy(p->name,name);
    p->chi=chi;
    p->mas=mas;
    p->pi=pi;
    p->next=NULL;
    return p;
} 
struct stu* bb(struct stu* b,struct stu* k)
{
    struct stu*i,*j;
    i=b;
    if(k->pi <= i->pi)
    {
        k->next=i;
        return k;
    }
    j=i;i=i->next;
    while(i!=NULL)
    {
       if(k->pi <= i->pi)
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
                printf(" %d: %d %5s %5.1f   %5.1f   %5.1f\n",r,q->id,q->name,q->chi,q->mas,q->pi); r++; q=q->next;
            }
 }
 void delete_id (struct stu*head,int t)
 {
    int r=1;
    int b;
    int i=1;
    struct stu*p,*q;
    p=head;
    q=p;
    printf("Your should choose the number include 1-%d:",t);
    scanf("%d",&b);
    printf("selunm = %d\n",b);
    if(b==1)
    {
        //printf("Your should choose the number include 1-%d:",t);
        //scanf("%d",&b);
        //printf("selunm = %d\n",b);
        p=head->next;
        while(p!=NULL)
        {
                                 
                printf(" %d: %d %5s %5.1f   %5.1f   %5.1f\n",r,p->id,p->name,p->chi,p->mas,p->pi); 
                r++;
                p=p->next;
        }
        
    }else{
    while(p!=NULL)
    {
        i++;
        if(i == b)
        {
            p->next=p->next->next;
        }    
        p=p->next;
    }    
    //printf("Your should choose the number include 1-%d:",t);
    //scanf("%d",&b);
    //printf("selunm = %d\n",b);
        while(q!=NULL)
        {
                        
                printf(" %d: %d %5s %5.1f   %5.1f   %5.1f\n",r,q->id,q->name,q->chi,q->mas,q->pi); 
                r++;
                q=q->next;
        }
    }   
 }
 void delete_name (struct stu*head,int h)
 {
    int r=1;
    int i=1;
    struct stu*p,*q;
    p=head;
    q=p;
    if(h==1)
    {
        p=head->next;
        while(p!=NULL)
        {
                        
                printf(" %d: %d %5s %5.1f   %5.1f   %5.1f\n",r,p->id,p->name,p->chi,p->mas,p->pi); 
                r++;
                p=p->next;
        }
        
    }else{
    while(p!=NULL)
    {
        i++;
        if(i == h)
        {
            p->next=p->next->next;
        }    
        p=p->next;
    }    
        while(q!=NULL)
        {
                        
                printf(" %d: %d %5s %5.1f   %5.1f   %5.1f\n",r,q->id,q->name,q->chi,q->mas,q->pi); 
                r++;
                q=q->next;
        }
    }   
 }
 int main(int argc, const char *argv[])
 {
    int w,a;int t=7;
    int b;
    float c,d,e,f;
    struct stu*q,*t0,*p,*t1;
    FILE*s;
    int i=0;int j=0;
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
    char bu[300]={0};
        s=fopen("1.txt","w");
        for(i=0;i<t;i++)
            {
              fprintf(s," %d %5s %5.1f   %5.1f    %5.1f\n",m[i].id,m[i].name,m[i].chi,m[i].mas,m[i].pi); 
              
            };
            fclose(s);
            s=fopen("1.txt","r");
            t1=tt_1(s);        
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
        if(w==1)  
        { 
            fclose(s);
            s=fopen("1.txt","r");
            while(fgets(bu,300,s))
            {
                printf(" %d: %s\n",r,bu);
                r++;
            }
            printf("-----------------------------------------\n");
        }   
        if(w==2)
        {
            fclose(s);
            s=fopen("1.txt","r");
            p=tt_1(s);
            t0=p;
            aa(t0);
            printf("%d",p->id);
        }
        if(w==3)
        {
            struct stu *x;
            fclose(s);
            x=malloc(sizeof(struct stu)*100);
            printf("Please input the new info(ID name chgrade mathgrade average):\n");
            printf("ID shuould more than 7\n");
            s=fopen("1.txt","a+");
            fscanf(stdin," %d%s%f%f%f",&x->id,x->name,&x->chi,&x->mas,&x->pi);
            getchar();
            fprintf(s," %d %5s %5.1f   %5.1f    %5.1f",x->id,x->name,x->chi,x->mas,x->pi);
            t++;
            
            fflush(s);
        }
        if(w==4)
        {
            printf("please choose the way:\n");
            printf("1.Delete by ID\n");
            printf("2.Delete by name\n");
            printf("3.Exit\n");
            printf("Your choice:");
            scanf("%d",&a);
            if(a == 3)
            continue;
            if(a>3)
            {
                printf("wrong");
                continue;
            }
            //printf("Your should choose the number include 1-%d:",t);
            //scanf("%d",&b);
            //printf("selunm = %d\n",b);
            //printf("r = %d\n",r);
            if(a == 1)
            delete_id(t1,t);
            if(a == 2)
            delete_name(t1,t);
        }
        if(w==5)
        break;
    }
    return 0;
 }

