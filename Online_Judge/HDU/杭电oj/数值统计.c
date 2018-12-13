#include <stdio.h>
#include <stdlib.h>
#define N 100

void sta(double a[], int n);

int main(void)
{
    int n;
    double a[N];

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            ;
        else
        {
            int i;
            for(i = 0; i < n; i++)
                scanf("%lf", &a[i]);

            sta(a, n);
        }
    }

    return 0;
}

void sta(double a[], int n)
{
    int cntne = 0, cnt0 = 0, cntpa = 0;
    int i;

    for(i = 0; i < n; i++)
    {
        if(a[i] < 0)
            cntne++;
        else if(a[i] == 0)
            cnt0++;
        else
            cntpa++;
    }

    printf("%d %d %d\n", cntne, cnt0, cntpa);

}
