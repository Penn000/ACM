//2017-04-04
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int s[2005], d[2005], dp[2005];//dp[i]表示前i个人所需要的最短时间
//状态转移方程：dp[i] = min(dp[i-1]+s[i], dp[i-2]+d[i-1])

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		  	scanf("%d", &s[i]);
		for(int i = 0; i < n-1; i++)
		  	scanf("%d", &d[i]);
		dp[0] = s[0];
		dp[1] = min(dp[0]+s[1], d[0]);
		for(int i = 2; i < n; i++)
		  	dp[i] = min(dp[i-1]+s[i], dp[i-2]+d[i-1]);
		int h, m, s;
		h = 8+dp[n-1]/3600;
		m = (dp[n-1]%3600)/60;
		s = dp[n-1]%60;
		if(h < 12)printf("%02d:%02d:%02d am\n", h, m, s);
		else printf("%02d:%02d:%02d pm\n", h, m, s);
	}

    return 0;
}
