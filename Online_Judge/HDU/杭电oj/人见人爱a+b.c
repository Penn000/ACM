#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int a[3], b[3], i;

        for(i = 0; i < 3; i++)
            scanf("%d", &a[i]);
        for(i = 0; i < 3; i++)
            scanf("%d", &b[i]);

        for(i = 0; i < 3; i++)
            a[i] += b[i];

        for(i = 2; i > 0; i--)
        {
            if(a[i] >= 60)
            {
                a[i] -= 60;
                a[i-1]++;
            }
        }

        for(i = 0; i < 3; i++)
            if(i == 2)
                printf("%d\n", a[i]);
            else
                printf("%d ",a[i]);
    }

    return 0;
}
