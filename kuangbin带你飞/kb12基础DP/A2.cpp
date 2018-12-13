//2017-04-04
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000005;
const int inf = 0x3f3f3f3f;
int s[N], dp[N], mx[N];

int main()
{
	int n, m, maxx;
	while(scanf("%d%d", &m, &n)!=EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &s[i]);
			dp[i] = 0;
			mx[i] = 0;
		}
		dp[0] = mx[0] = 0;
		for(int i = 1; i <= m; i++)
		{
			maxx = -inf;
			for(int j = i; j <= n; j++)
			{
				dp[j] = max(dp[j-1]+s[j], mx[j-1]+s[j]);
				mx[j-1] = maxx;
				maxx = max(maxx, dp[j]);
			}
		}
		cout<<maxx<<endl;
	}

    return 0;
}
