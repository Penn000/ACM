#include <stdio.h>
#include <stdlib.h>

void average(int m, int n);

int main(void)
{
    int m, n;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        average(m,n);
    }

    return 0;
}

void average(int m, int n)
{
    int i, sum = 0, cnt = 0;

    for(i = 1; i <= n; i++)
    {
        sum += 2*i;
        if(i%m == 0 && i < n)
        {
            printf("%d ", sum/m);
            sum = 0;
            cnt++;
        }
        if(i == n)
        {
            printf("%d\n", sum/(n-m*cnt));
        }
    }

}
