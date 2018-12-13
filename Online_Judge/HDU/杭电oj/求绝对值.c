#include <stdio.h>
#include <stdlib.h>

void abs_value(double a);

int main(void)
{
    double a;

    while(scanf("%lf", &a) != EOF)
    {
        abs_value(a);
    }

    return 0;
}

void abs_value(double a)
{
    printf("%.2f\n", a>0?a:-a);
}
