#include <stdio.h>
#include <stdlib.h>
#define N 100

void oddSum(int a[], int n);

int main(void)
{
    int n, a[N];

    while(scanf("%d", &n) != EOF)
    {
        int i;
        for(i = 0; i < n; i++)
            scanf("%d",&a[i]);

        oddSum(a, n);
    }

    return 0;
}

void oddSum(int a[], int n)
{
    int i, sum = 1;

    for(i = 0; i < n; i++)
    {
        if(a[i]%2==1)
        {
            sum *= a[i];
        }
    }

    printf("%d\n", sum);
}
