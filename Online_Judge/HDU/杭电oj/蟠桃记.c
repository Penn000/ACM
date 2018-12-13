#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        int i, sum = 1;

        for(i = n-1; i > 0; i--)
        {
            sum = (sum + 1) * 2;
        }

        printf("%d\n", sum);
    }

    return 0;
}
