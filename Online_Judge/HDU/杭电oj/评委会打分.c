#include <stdio.h>
#include <stdlib.h>

void judge(int *a, int n);

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int *a, i;
        a = (int*)malloc(n*sizeof(int));

        for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

        judge(a , n);
    }

    return 0;
}

void judge(int *a, int n)
{
    int i,sum = a[0], min, max;
    double  ave;

    min = max = a[0];
    for(i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];

        sum += a[i];
    }

    ave = (double)(sum - max - min)/(n-2.0);

    printf("%.2f\n", ave);
}
