#include <stdio.h>
#include <stdlib.h>
#define N 101

int main(void)
{
    int T, j;
    scanf("%d", &T);
    getchar();
    char **str;
    str  = (char**)malloc(T*sizeof(char*));
    for(j = 0; j < T; j++)
        str[j] = (char*)malloc(N*sizeof(char));

    for(j = 0; j < T; j++)
        gets(str[j]);

    for(j = 0 ; j < T; j++)
    {
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        char  *p = str[j];

        while(*p != '\0')
        {
            if(*p == 'a')
                a++;
            else if(*p == 'e')
                e++;
            else if(*p == 'i')
                i++;
            else if(*p == 'o')
                o++;
            else if(*p == 'u')
                u++;
            else
                ;

            p++;
        }

        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, i, o, u);

        if(j != T-1)
            printf("\n");
    }

    return 0;
}

