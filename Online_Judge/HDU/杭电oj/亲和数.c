#include <stdio.h>
#include <stdlib.h>

int divisorSum(int n);

int main(void)
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if(divisorSum(a) == b && divisorSum(b) == a)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

int divisorSum(int n)
{
    int sum = 0, i;

    for(i = 1; i < n; i++)
    {
        if(n%i == 0)
            sum += i;
    }

    return sum;
}
