//2017-10-08
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010;
const int L = 5010;
int n, l, w[N];
long long dp[L][5], v[N];//dp[j][k]表示容量为j的背包，有k个物品重量折半放入时的最大价值。

int main()
{
    int T, kase = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &l);
		l *= 2;//为防止出现浮点数，总容量和每个物品的重量都乘2。
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d%lld", &w[i], &v[i]);
			w[i] *= 2;
			ans = max(ans, v[i]);//只取一个物品时，无论重量为多少都可以取。
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++){
			for(int j = l; j >= w[i]/2; j--){
				for(int k = 0; k <= 2; k++){
					if(j >= w[i])dp[j][k] = max(dp[j][k], dp[j-w[i]][k]+v[i]);
					if(k && j >= w[i]/2)dp[j][k] = max(dp[j][k], dp[j-w[i]/2][k-1]+v[i]);
				}
			}
		}
		for(int k = 0; k <= 2; k++)
			ans = max(ans, dp[l][k]);
		printf("Case #%d: %lld\n", ++kase, ans);
	}

	return 0;
}
