#include <stdio.h>
#include <stdlib.h>
#define  N 50

int bigger_abs(int a, int b);
void bubbleSort(int *a, int n, int compare(int, int));

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            continue;
        int a[N], i;

        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        bubbleSort(a, n, bigger_abs);

        for(i = 0; i < n; i++)
        {
            if(i == n-1)
                printf("%d\n", a[i]);
            else
                printf("%d ", a[i]);
        }
    }
}

int bigger_abs(int a, int b)
{
    int  A, B;
    A = a > 0 ? a : -a;
    B = b > 0 ? b : -b;

    return A > B;
}

void bubbleSort(int *a, int n, int compare(int, int))
{
    int temp;
    int i, j,exchange = 0;
    for(i = 0; i < n-1; i++)
    {
        exchange = 0;
        for(j = 0; j < n-1-i; j++)
        {
            if(compare(a[j+1], a[j]))
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                exchange = 1;
            }
        }
        if(exchange == 0)
            break;
    }
}
