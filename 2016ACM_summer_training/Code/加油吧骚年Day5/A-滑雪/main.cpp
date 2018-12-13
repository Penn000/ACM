//2016.8.5
//POJ1088
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n, m;
int h[105][105];
int dp[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y)
{
	if(dp[x][y])return dp[x][y];
	int tmp, maxl = 0;
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&h[nx][ny]<h[x][y])
		{
			tmp = dfs(nx, ny);
			if(tmp>maxl)maxl = tmp;
		}
	}
	return dp[x][y] = maxl+1;
}

int main()
{
	while(cin>>n>>m)
	{
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++)
			scanf("%d", &h[i][j]);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++)
			dfs(i, j);
		int maxlen = 0;
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++)
			if(dp[i][j]>maxlen)
			  maxlen = dp[i][j];
		cout<<maxlen<<endl;
	}

	return 0;
}
