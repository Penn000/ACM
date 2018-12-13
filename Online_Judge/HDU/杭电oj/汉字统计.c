#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main(void)
{
    int T;
    scanf("%d", &T);

    getchar();
    while(T--)
    {
        int cnt = 0;
        char a[N], *p = a;
        gets(a);

        while(*p != '\0')
        {
           if(*p < 0)
                cnt++;

            p++;
        }

        printf("%d\n", cnt/2);
    }

    return 0;
}
