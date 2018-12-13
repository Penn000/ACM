#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 1000

void change(int n, int r);

int main(void)
{
    int n, r;

    while(scanf("%d %d", &n, &r) != EOF)
    {
        change(n, r);
    }

    return 0;
}

void change(int n, int r)
{
    char a[N];
    int i;
    if(n > 0)
    {
        itoa(n, a, r);
        for(i = 0; a[i] != '\0'; i++)
            if(/*a[i] >= 'a' && a[i] <= 'f'*/islower(a[i]))
                //a[i] -= 32;
                a[i] = toupper(a[i]);
        puts(a);
    }
    else
    {
        itoa(-n, a,r);
        for(i = 0; a[i] != '\0'; i++)
            if(/*a[i] >= 'a' && a[i] <= 'f'*/islower(a[i]))
                // a[i] -= 32;
                a[i] = toupper(a[i]);
        printf("-");
        puts(a);
    }
}
