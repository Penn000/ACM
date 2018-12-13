#include <stdio.h>
#include <stdlib.h>
#define N 100

void sort(int *a, int n, int m);

int main(void)
{
    int m, n;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(n == 0 && m == 0)
            continue;
        int a[N], i;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);

        sort(a, n, m);

        for(i = 0; i <= n; i++)
        {
            if(i == n)
                printf("%d\n", a[i]);
            else
                printf("%d ", a[i]);
        }
    }

    return 0;
}


void sort(int *a, int n, int m)
{
    int i;
    for(i = n-1; i >= 0; i--)
    {
        if(a[i] > m)
            a[i+1] = a[i];
        else{
             a[i+1] = m;
             break;
        }
    }
    if(i <= 0)
        a[0] = m;
}






