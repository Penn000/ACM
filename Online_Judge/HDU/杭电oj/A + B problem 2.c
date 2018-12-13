#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1001

void add(char s1[], char s2[]);

int main(void)
{
    char a[N], b[N];
    int T, i = 1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%s %s", a, b);
        printf("Case %d:\n%s + %s = ", i, a, b);
        i++;
        add(a, b);
        if(T>0)
        printf("\n");
    }

    return 0;
}

void add(char s1[], char s2[])
{
    int num1[N] = {0}, num2[N] = {0};
    int i, j, len1, len2, len3;
    len1 = strlen(s1);
    len2 = strlen(s2);
    len3 = len1>len2?len1:len2;

    for(i = len1-1, j = 0; i >= 0; i--)
    {
        num1[j++] = s1[i] - '0';
    }
    for(i = len2-1, j = 0; i >= 0; i--)
    {
        num2[j++] = s2[i] - '0';
    }
    for(i = 0; i < len3 + 1; i++)
    {
        num1[i] += num2[i];
        if(num1[i]>9)
        {
            num1[i] -= 10;
            num1[i+1]++;
        }
    }
    if(num1[len3]!=0)
    {
        printf("%d",num1[len3]);
    }
    for(i = len3-1; i >= 0; i--)
    {
        printf("%d", num1[i]);
    }
    printf("\n");
}
