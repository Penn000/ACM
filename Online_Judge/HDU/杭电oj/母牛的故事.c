/*有一头母牛，它每年年初生一头小母牛。
每头小母牛从第四个年头开始，每年年初也生一头小母牛。
请编程实现在第n年的时候，共有多少头母牛？*/

/*递归思想， 今年的牛为去年的牛加上三年前的牛， 三年前的牛各生一只小牛 */

    #include <stdio.h>
    #include <stdlib.h>

    int main(void)
    {
        int n;
        while(scanf("%d", &n) != EOF)
        {
            if(n == 0)
                continue;
            int i , num[56];
            num[0] = 1;
            num[1] = 2;
            num[2] = 3;
            for(i = 3; i < n; i++)
            {
                num[i] = num[i-1] +num[i-3];
            }

            printf("%d\n", num[n-1]);
        }
        return 0;
    }
