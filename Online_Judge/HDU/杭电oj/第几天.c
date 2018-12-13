#include <stdio.h>
#include <stdlib.h>

void dayth(int y, int m, int d);

int main(void)
{
    int y, m, d;

    while(scanf("%d/%d/%d", &y ,&m, &d) != EOF)
    {
        dayth(y, m, d);
    }

    return 0;
}

void dayth(int y, int m, int d)
{
    int Dayth = 0, i;
    int a1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int a2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((y%4==0&&y%100!=0)||(y%400==0))
    {
        for(i = 0; i < m-1; i++)
            Dayth += a2[i];
        Dayth += d;
    }
    else
    {
        for(i = 0; i < m-1; i++)
            Dayth += a1[i];
        Dayth += d;
    }

    printf("%d\n", Dayth);
}
