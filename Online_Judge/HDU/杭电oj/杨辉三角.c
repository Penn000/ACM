#include <stdio.h>
#include <stdlib.h>
#define N 31

void yanghui(int a[][N], int n);

int main(void)
{
    int n, a[N][N];

    while(scanf("%d", &n) != EOF)
    {
        yanghui(a, n);
        printf("\n");
    }

    return 0;
}

void yanghui(int a[][N], int n)
{
    int i, j;

     for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    for(i = 0; i < n; i++)
    {
       a[i][0]=a[i][i]=1;
       for(j = 0; j < i; j++)
       {
           if(j>=1)
           a[i][j]=a[i-1][j-1]+ a[i-1][j];
       }
    }

    for(i = 0; i < n; i++)
    {
         for(j = 0; j <= i; j++)
         {
             if(j == i)
                printf("%d", a[i][j]);
             else
                 printf("%d ", a[i][j]);

         }
          printf("\n");
  }
}
