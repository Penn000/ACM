#include <stdio.h>
#include <stdlib.h>
#define N 100

int comp(const void*a,const void*b);
int search(int x, int b[], int n);

int main(void)
{
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(n ==0 && m == 0)
            continue;
        int *a, *b, c[N], i, len = 0;
        a = (int *)malloc(n * sizeof(int));
        b = (int *)malloc(m * sizeof(int));

        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < m; i++)
            scanf("%d", &b[i]);

        for(i = 0; i < n; i++)
        {
            if(!search(a[i], b, m))
            {
                c[len] = a[i];
                len++;
            }
        }

        if(len > 0)
        {
            qsort(c,len, sizeof(int), comp);
            for(i = 0; i < len; i++)
                printf("%d ", c[i]);
            printf("\n");
        }
        else
            printf("NULL\n");
    }

    return 0;
}

int search(int x, int b[], int n)
{
    int i, flag = 0;

    for(i = 0; i < n; i++)
    {
        if(x == b[i])
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

int comp(const void*a,const void*b)
{
return *(int*)a-*(int*)b;
}
