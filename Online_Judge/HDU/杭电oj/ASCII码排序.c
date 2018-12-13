#include <stdio.h>
#include <stdlib.h>

void Asort(char a[], int n);

int main(void)
{
    char a[4];

    while(scanf("%s", a) != EOF)
    {
        Asort(a, 3);
        printf("%c %c %c\n", a[0], a[1], a[2]);
    }

    return 0;
}

void Asort(char a[], int n)
{
    char temp;
    int i, j,exchange = 0;
      for(i = 0; i < n-1; i++)
    {
        exchange = 0;
        for(j = 0; j < n-1-i; j++)
        {
            if(a[j]>a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    exchange = 1;
                }
        }
        if(exchange == 0)
            break;
    }
}
