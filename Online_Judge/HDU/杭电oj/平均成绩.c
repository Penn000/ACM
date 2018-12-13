#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        int **a, i, j, cnt = 0;
        double *stu_ave, *les_ave;
        a = (int **)malloc((n)*sizeof(int *));
        for(i = 0; i < n; i++)
            a[i] = (int *)malloc((m)*sizeof(int));
            stu_ave = (double *)malloc(n*sizeof(double));
            les_ave = (double *)malloc(m*sizeof(double));

        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                scanf("%d", &a[i][j]);

        for(i = 0; i < n; i++)
        {
            stu_ave[i] = 0;
            for(j = 0; j < m; j++)
            {
               stu_ave[i] += a[i][j];
            }
            stu_ave[i] /= m;
        }
        for(j = 0; j < m; j++)
        {
            les_ave[j] = 0;
            for(i = 0; i < n; i++)
            {
                 les_ave[j] += a[i][j];
            }
             les_ave[j] /= n;
        }

        int flag ;
        for(i = 0; i < n; i++)
        {
            flag = 1;
            for(j = 0; j < m; j++)
            {
                if(a[i][j] < les_ave[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                cnt++;
        }

        for(i = 0; i < n; i++)
        {
            if(i == n-1)
                printf("%.2f\n", stu_ave[i]);
            else
                printf("%.2f ", stu_ave[i]);
        }

        for(i = 0; i < m; i++)
        {
            if(i == m-1)
                printf("%.2f\n", les_ave[i]);
            else
                printf("%.2f ", les_ave[i]);
        }

        printf("%d\n\n", cnt);
    }

    return 0;
}
