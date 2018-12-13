//2016.10.7
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1005;
long long arr[N], dp[N];

int main()
{
	int n;
	long long ans;
	while(scanf("%d", &n)!=EOF && n)
	{
		ans = 0;
		for(int i = 0; i < n; i++)
		  	scanf("%lld", &arr[i]);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			dp[i] = arr[i];
			for(int j = 0; j < i; j++)
			  	if(arr[i] > arr[j])
				  	dp[i] = max(dp[i], dp[j]+arr[i]);//状态转移方程
			ans = max(ans, dp[i]);
		}
		printf("%lld\n", ans);
	}

    return 0;
}
