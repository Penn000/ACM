/**************************************************************************************************************************************
Input

�������ݰ����������ʵ����ÿ������ʵ��ռһ�У�ÿ�еĿ�ʼ��һ������n(3<=n<=100)��
����ʾ����εı�������ȻҲ�Ƕ���������Ȼ���ǰ�����ʱ��˳�������n����������꣨x1, y1, x2, y2... xn, yn��,
Ϊ�˼����⣬������������궼��������ʾ��
�������������е���������32λ������Χ�ڣ�n=0��ʾ���ݵĽ�������������





Output

����ÿ������ʵ�����������Ӧ�Ķ��������������ȷ��С�����һλС����
ÿ��ʵ�������ռһ�С�





Sample Input

3 0 0 1 0 0 1
4 1 0 0 1 -1 0 0 -1
0





Sample Output

0.5
2.0

*******************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double singleArea(int x1, int y1, int x2, int y2, int x3, int y3);
double sumArea(int *a, int n);

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            continue;
        int *a, i;
        a = (int *)malloc(2*n*sizeof(int));

        for(i = 0; i < 2*n; i++)
            scanf("%d", &a[i]);

        sumArea(a, 2*n);
    }

    return 0;
}

double singleArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double area;
    area = fabs(0.5*(double)((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1)));
    return area;
}

double sumArea(int *a, int n)
{
    double sum = 0;
    int i;
    for(i = 2; i < n-3; i+=2)
    sum += singleArea(a[0], a[1], a[i], a[i+1], a[i+2], a[i+3]);

    printf("%.1f\n", sum);
}





