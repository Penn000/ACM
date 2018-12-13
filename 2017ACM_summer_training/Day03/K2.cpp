//2017-08-03
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 110;
const int MOD = 999983;
int n, m;
long long dp[N][N][N];//dp[i][j][k]表示处理到第i行，一列上有0个炮的列数j，一列上有1个炮的列数k的方案数。

inline long long cal(int a, int b)
{
    return b == 1 ? a : (1LL * a * (a - 1) / 2) % MOD;
}

int main()
{
    while (scanf("%d%d", &n, &m)!=EOF)
    {
        memset(dp, 0, sizeof(dp));
        long long ans = 0;
        dp[0][m][0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= m; ++k)
                    if (dp[i][j][k])
                    {
                        (dp[i + 1][j][k] += dp[i][j][k]) %= MOD;
                        if (j > 0)
                            (dp[i + 1][j - 1][k + 1] += dp[i][j][k] * cal(j, 1)) %= MOD;
                        if (j > 1)
                            (dp[i + 1][j - 2][k + 2] += dp[i][j][k] * cal(j, 2)) %= MOD;
                        if (j > 0)
                            (dp[i + 1][j - 1][k] += dp[i][j][k] * cal(j, 1) % MOD * cal(k, 1)) %= MOD;
                        if (k > 0)
                            (dp[i + 1][j][k - 1] += dp[i][j][k] * cal(k, 1)) %= MOD;
                        if (k > 1)
                            (dp[i + 1][j][k - 2] += dp[i][j][k] * cal(k, 2)) %= MOD;
                    }
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= m; ++j)
                ans = (ans + dp[n][i][j]) % MOD;
        printf("%lld\n", ans);
    }
}
