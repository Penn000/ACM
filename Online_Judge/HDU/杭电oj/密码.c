#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define N 50

int main(void)
{
    int T;
    scanf("%d", &T);
    getchar();

    while(T--)
    {
        int i, len, sum = 0, type[4] = {0};
        char a[N], *p = a;
        gets(a);

        len = strlen(a);
        if(len >= 8 && len <= 16)
        {
            while(*p != '\0')
            {
                if(*p >= 'A' && *p <= 'Z')
                    type[0] = 1;
                if(*p >= 'a' && *p <= 'z')
                    type[1] = 1;
                if(*p >= '0' && *p <= '9')
                    type[2] = 1;
                if(*p == '~' || *p == '!' || *p == '@' || *p == '#' || *p == '$' || *p == '%'|| *p == '^')
                    type[3] = 1;

                p++;
            }
            for(i = 0; i < 4; i++)
                sum += type[i];

            if(sum >= 3)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
