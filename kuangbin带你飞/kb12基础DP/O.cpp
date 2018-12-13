//2017-04-06
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2005;
int v[N], n, dp[N][N];//dp[l][r]表示区间l~r间的最大收益
//状态转移方程：dp[l][r] = max(dp[l+1][r]+day*v[l], dp[l][r-1]+day*v[r])

int dfs(int l, int r, int day)
{
	if(l > r)return 0;
	if(dp[l][r])return dp[l][r];
	if(l == r)return dp[l][r] = day*v[l];
	return dp[l][r] = max(dfs(l+1, r, day+1)+day*v[l], dfs(l, r-1, day+1)+day*v[r]);
}

int main()
{
	while(scanf("%d", &n)!=EOF)
	{
		for(int i = 0; i < n; i++)
		  	scanf("%d", &v[i]);
		memset(dp, 0, sizeof(dp));
		int ans = dfs(0, n-1, 1);
		printf("%d\n", ans);
	}

    return 0;
}
