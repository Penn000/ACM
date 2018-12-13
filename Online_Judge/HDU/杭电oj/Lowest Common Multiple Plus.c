#include <stdio.h>
#include <stdlib.h>

unsigned int LCMP(unsigned int a, unsigned int b);

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        unsigned int i, *a, mulPlus;
        a = (unsigned int *)malloc(n*sizeof(unsigned int));

        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);

        mulPlus = LCMP(a[0], a[1]);
        for(i = 2; i < n; i++)
            mulPlus = LCMP(mulPlus, a[i]);

        printf("%d\n", mulPlus);
    }

    return 0;
}

unsigned int LCMP(unsigned int a, unsigned int b)
{
    unsigned int r, m = a, n = b;

    while(n != 0)
    {
        r = m%n;
        m = n;
        n = r;
    }

    return a / m * b;
}
