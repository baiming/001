#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a[10]="hello.word";
    int i=6;
    while (i<10)
    {
        putchar(a[i]);
        i++;
    }
    i=0;
    while (i<6) 
    {
        putchar(a[i]);
        i++;
    }

    return 0;
}
