#include <stdio.h>
#include <stdlib.h>

int sum(int n);

int main(void)
{
    int n, thesum;

    while(scanf("%d", &n) != EOF)
    {
        thesum = sum(n);
        printf("%d\n\n", thesum);
    }

    return 0;
}

int sum(int n)
{
    int i, Sum = 0;

    for(i = 1; i <= n; i++)
    {
        Sum += i;
    }

    return Sum;
}
