#include <stdio.h>
#include <stdlib.h>
#define N 101

int main(void)
{
    char a[N];
    while((a[0] = getchar()) != EOF)
    {
        char *p = a;
        *p -= 32;
        p++;
        gets(p);


        for( ; *p != '\0'; p++)
        {
            if(*p == ' ')
            {
                *(p+1) -= 32;
            }
        }

        puts(a);
    }

    return 0;
}


