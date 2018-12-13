#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Sum(int m, int n);

int main(void)
{
    int m, n;

    while(scanf("%d %d", &m, &n) != EOF)
    {
        Sum(m, n);
    }

    return 0;
}

void Sum(int m, int n)
{
    double sum = m, next;
    int i;

    next = sqrt(m);
    for(i = 1; i < n; i++)
    {
        sum += next;
        next = sqrt(next);
    }

    printf("%.2f\n", sum);
}
