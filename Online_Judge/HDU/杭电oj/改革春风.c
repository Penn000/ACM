/**************************************************************************************************************************************
Input

输入数据包含多个测试实例，每个测试实例占一行，每行的开始是一个整数n(3<=n<=100)，
它表示多边形的边数（当然也是顶点数），然后是按照逆时针顺序给出的n个顶点的坐标（x1, y1, x2, y2... xn, yn）,
为了简化问题，这里的所有坐标都用整数表示。
输入数据中所有的整数都在32位整数范围内，n=0表示数据的结束，不做处理。





Output

对于每个测试实例，请输出对应的多边形面积，结果精确到小数点后一位小数。
每个实例的输出占一行。





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





