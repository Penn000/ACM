//2017-05-23
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
const int inf = 0x3f3f3f3f;
int D[N], dp[N][N], sum[N];

int main()
{
    int T, n;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
		  	scanf("%d", &D[i]);
			if(i == 0)sum[i] = D[i];
			else sum[i] = sum[i-1] + D[i];
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++)
		  	for(int j = i+1; j < n; j++)
			  	dp[i][j] = inf;
		for(int len = 1; len <= n; len++){
			for(int l = 0; l+len <= n; l++){
				int r = l+len-1;
				for(int k = 1; k <= len; k++){
					dp[l][r] = min(dp[l][r], dp[l+1][l+k-1]+dp[l+k][r]+(k-1)*D[l]+(sum[r]-sum[l+k-1])*k);
				}
			}
		}
		printf("Case #%d: %d\n", kase, dp[0][n-1]);
	}

	return 0;
}
