#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void judge(char *a);

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        getchar();
        int i;
        char** a;
        a = (char**)malloc(n*sizeof(char*));
        for(i = 0; i < n; i++)
            a[i] = (char*)malloc(51*sizeof(char));

        for(i = 0; i < n; i++)
        {
            gets(a[i]);
            judge(a[i]);
        }
    }

    return 0;
}

void judge(char *a)
{
    char *p = a, flag = 1;
    if(!((*p >= 'a' && *p <= 'z')||(*p >= 'A' && *p <= 'Z')||(*p == '_')))
        printf("no\n");
    else
    {
        p++;
        while(*p != '\0')
        {
            if(!(isalnum(*p)||*p == '_'))
            //if(!((*p >= 'a' && *p <= 'z')||(*p == '_')||(*p >= '0' && *p <= '9')||(*p >= 'A' && *p <= 'Z')))
            {
                printf("no\n");
                flag = 0;
                break;
            }
            p++;
        }
        if(flag)
            printf("yes\n");
    }
}
