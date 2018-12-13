#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;

    while(scanf("%d %d", &a, &b) != EOF)
    {
        if(a == 0 && b == 0)
            continue;
        int out = 1, i;

        for(i = 0; i < b; i++)
        {
            out *= a;
            out %= 1000;
        }

        printf("%d\n", out);
    }

    return 0;
}
