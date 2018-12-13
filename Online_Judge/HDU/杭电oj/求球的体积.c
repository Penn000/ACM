#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415927

void volume(double r);

int main(void)
{
    double r;

    while(scanf("%lf", &r) != EOF)
    {
        volume(r);
    }

    return 0;
}

void volume(double r)
{
    double V;

    V = (4.0/3.0)*PI*r*r*r;

    printf("%.3f\n",V);
}
