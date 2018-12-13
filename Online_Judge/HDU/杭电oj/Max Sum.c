//时间超限，网上说用分治。
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
    int i = 0, max_sum, temp, bg, ed, Bg, Ed;

    for(i = 0; i < n; i++)
    {
        if(a[i]>=0)
            break;
    }
    bg = i;

    if(bg >= n)
    {
        max_sum = a[0];
        Bg = Ed = 0;
        for(i = 1; i < n; i++)
        {
            if(a[i]>max_sum)
            {
                max_sum = a[i];
                Bg = Ed = i;
            }
        }
    }
    else
    {
        max_sum = temp = a[bg];
        Bg = bg;
        Ed = ed;
        for(i = bg+1; i < n; i++)
        {
            temp += a[i];
            if(temp > max_sum)
            {
                max_sum = temp;
                Ed = i;
            }
            if(temp < 0)
            {
                temp = 0;
                Bg = i;
            }
        }
    }
    /*max_sum = temp = a[bg];
    for(j = 0; j < ed-bg; j++)
    {
        for(i = bg+1; i <= ed-j; i++)
        {
            if(a[ed-j]<0)break;
            temp += a[i];
        }
        if(temp > max_sum)
        {
            max_sum = temp;
            Ed = ed-j;
        }
        temp = a[bg];
    }*/

    printf("%d %d %d\n", max_sum, Bg+1, Ed+1);
}














