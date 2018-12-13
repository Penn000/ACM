//2016.9.6
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;
int dp[N], c[N], w[N];

int main()
{
	int T, n, v;
	cin>>T;
	while(T--)
	{
		scanf("%d%d", &n, &v);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++)
		  	scanf("%d", &w[i]);
		for(int i = 0; i < n; i++)
		  	scanf("%d", &c[i]);
		for(int i = 0; i < n; i++)
		  	for(int j = v; j >= c[i]; j--)
			  	dp[j] = max(dp[j], dp[j-c[i]]+w[i]);
		printf("%d\n", dp[v]);
	}

    return 0;
}
