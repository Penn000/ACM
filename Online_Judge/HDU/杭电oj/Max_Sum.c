#include <stdio.h>
#include <stdlib.h>
#define N 100000

void MaxSum(int a[], int n);

int a[N];

int main(void)
{
    int T, n, Case = 1, i;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        printf("Case %d:\n", Case);
        Case++;

        MaxSum(a, n);

        if(T>0)
            printf("\n");
    }


    return 0;
}

void MaxSum(int a[], int n)
{
    int i = 0, max_sum, temp, bg, Bg, ed, Ed;

    max_sum = temp = a[0];
    bg = Bg = ed = Ed = 0;
    for(i = 1; i < n; i++)
    {
         if(temp < 0)
        {
            temp = 0;
            bg = i;
        }
        temp += a[i];
        ed = i;
        if(temp > max_sum)
        {
            max_sum = temp;
            Bg = bg;
            Ed = ed;
        }
    }
    printf("%d %d %d\n", max_sum, Bg+1, Ed+1);
}















