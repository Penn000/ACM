//2017-08-03
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;
char str[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", str);
        int cnt = 0;
        bool fg = 1;
        if (str[0] == 'M')
        {
            for (int j = 1; j < strlen(str); j++)
            {
                if (str[j] == 'I')
                    cnt++;
                else if (str[j] == 'U')
                    cnt += 3;
                else if(str[j] == 'M')fg = 0;
            }
        }else{
            printf("No\n");
            continue;
        }
        if(fg == 0){
            printf("No\n");
            continue;
        }
        if (cnt <= 4)
        {
            if (cnt == 3 || cnt == 0)
                fg = 0;
            else
                fg = 1;
        }
        else
        {
            if (cnt % 2 == 1)
                fg = 0;
            else
            {
                cnt /= 2;
                if (cnt % 3 == 1 || cnt % 3 == 2)
                    fg = 1;
                else
                    fg = 0;
            }
        }
        if (fg)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}