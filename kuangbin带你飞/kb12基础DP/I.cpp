//2017-03-14
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000000;
int h[N], dp[N];//dp[i]表示第i位结尾的递增序列长度。
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &h[i]);
			for(int j = 0; j < i; j++)
			{
				if(h[j] < h[i] && dp[j] >= dp[i])
				  	dp[i] = dp[j]+1;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
		  	if(dp[i]>ans)ans = dp[i];
		printf("%d\n", ans+1);
	}

    return 0;
}
