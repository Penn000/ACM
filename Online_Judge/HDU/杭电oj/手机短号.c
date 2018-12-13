#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    getchar();

    while(T--)
    {
        char A[12], *p = &A[6];

        gets(A);

        printf("6");
        puts(p);
    }

    return 0;
}
