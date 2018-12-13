#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);

        if(a+b>c && a+c>b && b+c>a)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
