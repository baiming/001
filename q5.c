#include <stdio.h>
int main(int argc, const char *argv[])
{
    FILE*i,*j;char a[100];
    i=fopen(argv[1],"r");
    j=fopen(argv[2],"w");
    while(!feof(i))
    {  
        fgets(a,20,i);
        if(feof(i))
        break;
        fputs(a,j);
        printf("%s",a);
    }
     fclose(i);
     fclose(j);
    return 0;
}
//--------------------------------------

/*#include <stdio.h>
int main(int argc, const char *argv[])
{
    FILE*i,*j;int p;
    i=fopen(argv[1],"r");
    j=fopen(argv[2],"w");
    while(!feof(i))
    {  
       p= fgetc(i);
        if(feof(i))
        break;
        fputc(p,j);
        printf("%c\n",p);
     }
     fclose(i);
     fclose(j);
    return 0;
}*/

