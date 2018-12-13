#include <stdio.h>
#include <stdlib.h>

void change(int *a, int n);

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            continue;
        int *a, i;
        a = (int*)malloc(n*sizeof(int));

        for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

        change(a, n);
    }

    return 0;
}

void change(int *a, int n)
{
    int i, min = a[0], minnum;

    for(i = 1;i < n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
            minnum = i;
        }
    }
    if(a[0] == min)
        ;
    else
    {
        a[0] = a[0] ^ a[minnum];
        a[minnum] = a[0] ^ a[minnum];
        a[0] = a[0] ^ a[minnum];
    }

    for(i = 0; i < n; i++)
    {
        if(i == n-1)
            printf("%d\n", a[i]);
        else
            printf("%d ", a[i]);
    }
}
