#include <stdio.h>
#include <stdlib.h>
#define N 100
void compute(char *a);

int main(void)
{
    int n,i;
    char **a;

    scanf("%d", &n);
    getchar();
    a = (char**)malloc(n*sizeof(char*));
    for(i = 0; i < n; i++)
        a[i] = (char*)malloc(N*sizeof(char));
    for(i = 0; i < n; i++)
        gets(a[i]);
    for(i = 0; i < n; i++)
        compute(a[i]);

    return 0;
}

void compute(char *a)
{
    char *p = a;
    int cnt = 0;

    for( ; *p != '\0'; p++)
    {
        if(*p >= '0' && *p <= '9')
            cnt++;
    }

    printf("%d\n", cnt);
}
