//2016.8.5
//HDU2571
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int inf = 9999999;
int mapp[25][1005];
int dp[25][1005];
int n, m;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i = 1; i <= n; i++)
		  for(int j = 1; j <= m; j++)
			scanf("%d", &mapp[i][j]);
		memset(dp, -inf, sizeof(dp));
		dp[0][1] = dp[1][0] = 0;
		for(int i = 1; i <= n; i++)
		  for(int j = 1; j <= m; j++)
		  {
			  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			  for(int k = 2; k <= j; k++)
			  {
				  if(j%k==0)dp[i][j] = max(dp[i][j], dp[i][j/k]);
			  }
			  dp[i][j]+=mapp[i][j];
		  }
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
