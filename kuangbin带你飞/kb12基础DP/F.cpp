//2017-04-04
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int dp[10005], p[505], w[505];//dp[i]表示重量为i时最少的钱
//状态转移方程：dp[i] = min{dp[i-w[j]]+p[j] | 0<j<n}

int main()
{
	int T, n, E, F, W;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &E, &F);
		W = F-E;
		memset(dp, inf, sizeof(dp));
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
		  	scanf("%d%d", &p[i], &w[i]);
			if(p[i] < dp[w[i]])//考虑两种硬币重量相等时，选价值小的
				dp[w[i]] = p[i];
		}
		for(int i = 1; i <= W; i++){
			for(int j = 0; j < n; j++){
				if(w[j] > i)continue;
				if(dp[i-w[j]]+p[j] < dp[i])
				  	dp[i] = dp[i-w[j]]+p[j];
			}
		}
		if(dp[W] == inf)printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[W]);
	}

    return 0;
}
