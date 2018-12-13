#include <stdio.h>
#include <stdlib.h>
#define N 100
void sum(int n);
int main(void)
{
    int T, a[N], i;

    scanf("%d", &T);
    for(i = 0; i < T; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < T; i++)
        sum(a[i]);

    return 0;
}

void sum(int n)
{
    double thesum = 0;
    int temp = 1, i;

    for(i = 1; i <= n; i++)
    {
        thesum += temp * (1.0/i);
        temp = -temp;
    }

    printf("%.2f\n", thesum);
}
