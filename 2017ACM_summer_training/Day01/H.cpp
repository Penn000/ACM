//2017-08-01
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
char num[N];

int main()
{
    while (scanf("%s", num) != EOF)
    {
        int n = strlen(num);
        bool fg = false;
        for (int i = 0; i < n; i++)
        {
            if (num[i] == '0')
            {
                fg = true;
                printf("YES\n0\n");
                break;
            }
        }
        if(fg)continue;
        for (int a = 8; a < 1000; a += 8)
        {
            int tmp = a;
            for (int i = n - 1; i >= 0; i--)
            {
                if (num[i] - '0' == tmp % 10)
                {
                    tmp /= 10;
                }
            }
            if (!tmp && !fg)
            {
                printf("YES\n%d\n", a);
                fg = true;
                break;
            }
        }
        if (!fg)
            printf("NO\n");
    }

    return 0;
}
