#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int row, col;

    while(scanf("%d %d", &row, &col) != EOF)
    {
        int **a, i, j, max, ROW, COL;
        a = (int **)malloc(row*sizeof(int *));
        for(i = 0; i < row; i++)
            a[i] = (int *)malloc(col*sizeof(int));

       for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

        max = a[0][0];
        ROW = COL = 0;
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
           {
               if(abs(a[i][j]) > abs(max))
                {
                    max = a[i][j];
                    ROW = i;
                    COL = j;
                }
           }

        printf("%d %d %d\n", ROW+1, COL+1, max);
    }

    return 0;
}
