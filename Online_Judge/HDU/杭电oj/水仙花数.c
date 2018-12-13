#include <stdio.h>
#include <stdlib.h>

void findnum(int m, int n);

int main(void)
{
    int m, n;

    while(scanf("%d %d", &m, &n) != EOF)
    {
        findnum(m, n);
    }

    return 0;
}

void findnum(int m, int n)
{
    int x, a, b, c, flag = 0;

    for(x = m; x <= n; x++){
        a = x / 100;
        b = (x - 100 * a) / 10;
        c = x - 100 * a - 10 * b;
        if(x == a*a*a + b*b*b + c*c*c){
           if(flag == 0)
            printf("%d", x);
           else
            printf(" %d",x);
            flag = 1;
        }
    }
    if(flag == 1)
        printf("\n");
    if(flag == 0)
        printf("no\n");
}
