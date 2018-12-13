#include <stdio.h>
#include <stdlib.h>
#define N 10

int sky(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    while(n != 0)
    {
        if(sky(n))
            printf("%d is a Sky Number.\n", n);
        else
            printf("%d is not a Sky Number.\n", n);
        scanf("%d", &n);
    }
    return 0;
}

int sky(int n)
{
    int flag = 1, i, A = 0, B = 0, C = 0;
    char a[N], b[N], c[N];
    int aa[N], bb[N], cc[N];

    itoa(n, a, 10);
    itoa(n, b, 12);
    itoa(n, c, 16);

    i = 0;
    while(a[i] != '\0')
    {
        aa[i] = a[i] - '0';
        i++;
    }
    aa[i] = -1;
    i = 0;
    while(b[i] != '\0')
    {
        if(b[i] >= '0' && b[i] <= '9')
            bb[i] = b[i] - '0';
        else if(b[i] == 'a')
            bb[i] = 10;
        else
            bb[i] = 11;

        i++;
    }
    bb[i] = -1;
    i = 0;
    while(c[i] != '\0')
    {
        if(c[i] >= '0' && c[i] <= '9')
            cc[i] = c[i] - '0';
        else if(c[i] == 'a')
            cc[i] = 10;
        else if(c[i] == 'b')
            cc[i] = 11;
        else if(c[i] == 'c')
            cc[i] = 12;
        else if(c[i] == 'd')
            cc[i] = 13;
        else if(c[i] == 'e')
            cc[i] = 14;
        else if(c[i] == 'f')
            cc[i] = 15;

        i++;
    }
    cc[i] = -1;
    i = 0;
    while(aa[i] != -1)
    {
        A += aa[i];
        i++;
    }
    i = 0;
    while(bb[i] != -1)
    {
        B += bb[i];
        i++;
    }
    i = 0;
    while(cc[i] != -1)
    {
        C += cc[i];
        i++;
    }

    if(!(A==B && B==C))
        flag = 0;

    return flag;
}








