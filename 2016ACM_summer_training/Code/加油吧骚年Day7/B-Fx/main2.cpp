//2016.8.31
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[20][10000], bit[20], a, b;//dp[i][j]表示第i位<=j的数目

int F(int a)
{
	int ans = 0, len = 0;
	while(a)
	{
		ans += (a%10)*(1<<len);
		len++;
		a /= 10;
	}
	return ans;
}

int dfs(int pos, int num, int fg)
{
	if(pos == -1)return num>=0;
	if(num < 0)return 0;
	if(!fg && dp[pos][num]!=-1)//记忆化搜索
	  	return dp[pos][num];
	int ans = 0;
	int ed = fg?bit[pos]:9;
	for(int i = 0; i <= ed; i++)
	  	ans+=dfs(pos-1, num-i*(1<<pos), fg&&i==ed);
	if(!fg)dp[pos][num] = ans;
	return ans;
}

int solve(int b)
{
	int len = 0;
	while(b)
	{
		bit[len++] = b%10;
		b /= 10;
	}
	int ans = dfs(len-1, F(a), 1);
	return ans;
}

int main()
{
	int T, kase = 0;
	cin>>T;
	memset(dp, -1, sizeof(dp));
	while(T--)
	{
		scanf("%d%d", &a, &b);
		int ans = solve(b);
		printf("Case #%d: %d\n", ++kase, ans);
	}

    return 0;
}
