#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void len(double x1, double y1, double x2, double y2);

int main(void)
{
    double x1, x2, y1, y2;

    while(scanf("%lf %lf %lf %lf", &x1, &y1,&x2, &y2) != EOF)
    {
        len(x1,y1, x2, y2);
    }

    return 0;
}

void len(double x1, double y1, double x2, double y2)
{
     double Len;

     Len = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

     printf("%.2f\n", Len);
}
