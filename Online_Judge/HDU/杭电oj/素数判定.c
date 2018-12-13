#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n);

int main(void)
{
    int x, y;

    while(scanf("%d %d", &x, &y) != EOF)
    {
        if(x == 0 && y == 0)
            continue;

        int i, result;
        for(i = x; i <= y; i++)
        {
            result = i * i + i +41;
            if(!is_prime(result))
                break;
        }
        if(i <= y)
            printf("Sorry\n");
        else
            printf("OK\n");
    }

    return 0;
}

int is_prime(int n)
{
    int i, prime = 1;

    for(i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            prime = 0;
            break;
        }
    }

    return prime;
}
