#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 606

void getin(char a[], char *p, char *in);
char* findmax(char a[]);

int main(void)
{
   char in[6] = {"(max)"};
   char a[N];

    while(scanf("%s", a) != EOF)
    {
        char *max = a, *p = a;
        max = findmax(a);

        for( ; *p != '\0'; p++)
        {
            if(*p == *max)
            {
                getin(a, p, in);
                p += 5;
            }

        }

        puts(a);
    }

    return 0;
}

char* findmax(char a[])
{
    char *max = a, *p = a;
    while(*p != '\0')
    {
        if(*p > *max)
        {
            max = p;
        }
        p++;
    }

    return max;
}

void getin(char a[], char *p, char *in)
{
    char *q = p+1, temp[N];
    strcpy(temp, q);
    *q = '\0';
    strcat(a, in);
    strcat(a, temp);

}







