//2016.8.20
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double A, B, C, money[50], dp[50];//money[i]表示能报销的账单i的金额, dp[i]报销前i张所得到的最大金额

int main()
{
    double Q, price;
    int n, m, tot;
    char Type;
    bool fg;
    while(cin>>Q>>n&&n)
    {
        tot = 0;
        memset(money, 0, sizeof(money));
        memset(dp, 0, sizeof(dp));
        while(n--)
        {
            scanf("%d", &m);
            A = B = C = 0;
            fg = true;
            for(int i = 0; i < m; i++)
            {
                scanf(" %c:%lf", &Type, &price);
                if(Type!='A'&&Type!='B'&&Type!='C'||price>600)
                    fg = false;
                if(Type=='A')A+=price;
                else if(Type=='B')B+=price;
                else if(Type=='C')C+=price;
            }
            if(fg&&A<=600&&B<=600&&C<=600&&A+B+C<=1000)
                money[tot++] = A+B+C;
        }
        for(int i = 0; i <= tot; i++)
            for(int j = tot; j >= 1; j--)
                if(j==1||dp[j-1]>0&&dp[j-1]+money[i]<=Q)
                    dp[j] = max(dp[j], dp[j-1]+money[i]);

        double ans = 0;
        for(int i = 1; i <= tot; i++)
            if(ans<dp[i])
                ans = dp[i];

        printf("%.2lf\n", ans);
    }

    return 0;
}
