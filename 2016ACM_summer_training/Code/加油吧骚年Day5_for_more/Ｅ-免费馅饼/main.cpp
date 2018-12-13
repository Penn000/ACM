//2016.8.5
//HDU1176
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int mapp[100005][12], dp[100005][12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int dfs(int x, int y)
{
	if(dp[x][y])return dp[x][y];

}

int main()
{
	int n, x, t, tt;
	while(cin>>n&&n)
	{
		tt = 0;
		memset(mapp, 0, sizeof(mapp));
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &t);
			mapp[t][x]++;
			if(t>tt)tt = t;
		}
		for(int i = 0; i <= 10; i++)
		  dp[1][i] = 0;
		dp[1][5] = mapp[1][5];
		dp[1][4] = mapp[1][4];
		dp[1][6] = mapp[1][6];
		for(int i = 2; i <= tt; i++)
		{
			mapp[i][11] = 0;
			for(int j = 0; j <= 10; j++)
			{
				if(j==0)dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]);
				else dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1]));
				dp[i][j]+=mapp[i][j];
			}
		}
		int ans = 0;
		for(int i = 0; i <= 10; i++)
		{
			if(dp[tt][i]>ans)ans = dp[tt][i];
		}
		cout<<ans<<endl;
	}

	return 0; 
}
