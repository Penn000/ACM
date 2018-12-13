#include <stdio.h>
#include <stdlib.h>

void SUM(int m, int n);

int main(void)
{
    int m, n;

    while(scanf("%d %d", &m, &n) != EOF)
    {
        SUM(m, n);
    }

    return 0;
}

void SUM(int m, int n)
{
    if(m > n)
    {
        m = m ^ n;
        n = m ^ n;
        m = m ^ n;
    }
    int i = m;
    long sumodd = 0, sumeven = 0;

    for( ; i <= n; i++)
    {
        if(i%2==0)
        {
            sumeven += i*i;
        }else{
            sumodd += i*i*i;
        }
    }

    printf("%d %d\n", sumeven, sumodd);
}
