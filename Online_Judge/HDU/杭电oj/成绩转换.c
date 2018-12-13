#include <stdio.h>
#include <stdlib.h>

void change(int t);

int main(void)
{
    int t;

    while(scanf("%d", &t) != EOF)
    {
        change(t);
    }

    return 0;
}

void change(int t)
{
    if(t >= 90 && t <= 100)
        printf("A\n");
    else if(t >= 80 && t <= 89)
        printf("B\n");
    else if(t >= 70 && t <= 79)
        printf("C\n");
    else if(t >= 60 && t <= 69)
        printf("D\n");
    else if(t >= 0 && t <= 59)
        printf("E\n");
    else
        printf("Score is error!\n");
}
