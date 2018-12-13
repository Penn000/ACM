#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[100005], dp[100005];

int main()
{
	int T, n, k;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			dp[i] = a[i];
		}
		int mx = dp[0];
		int ans = 0;
		for(int i = k+1; i < n; i++)
		{
			mx = max(mx, dp[i-k-1]);
			dp[i] = a[i] + mx;
			if(ans < dp[i])ans = dp[i];
		}
		printf("%d\n", ans);
	}

	return 0;
}
