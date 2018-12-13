#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        getchar();
        while(T--)
        {
            char a[N];
            int len, flag = 1;

            fgets(a, N, stdin);
            len = strlen(a);
            char *p = a, *q = &a[len-2];

            while(q >= p)
            {
                if(*p != *q)
                {
                    flag = 0;
                    break;
                }
                p++;
                q--;
            }

            if(flag)
                printf("yes\n");
            else
                printf("no\n");
        }
    }

    return 0;
}
