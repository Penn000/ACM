//2016.8.30
#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 1005;
int n, m, a[maxn][maxn];
int dp1[maxn][maxn],dp2[maxn][maxn],dp3[maxn][maxn],dp4[maxn][maxn];
//dp1[i][j] := 从 (1, 1) 到 (i, j) 的最大分数 
//dp2[i][j] := 从 (i, j) 到 (n, m) 的最大分数 
//dp3[i][j] := 从 (n, 1) 到 (i, j) 的最大分数 
//dp4[i][j] := 从 (i, j) 到 (1, m) 的最大分数
int main()
{
	while(cin>>n>>m)
	{
		for(int i = 1; i <= n; i++)
		  for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; i++)
	  for(int j = 1; j <= m; j++)
		dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1])+a[i][j];
	
	for(int i = n; i >= 1; i--)
 	  for(int j = m; j >= 1; j--)
		dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1])+a[i][j];

	for(int i = n; i >= 1; i--)
  	  for(int j = 1; j <= m; j++)
		dp3[i][j] = a[i][j]+max(dp3[i][j-1], dp3[i+1][j]);

	for(int i = 1; i <= n; i++)
  	  for(int j = m; j >= 1; j--)
		dp4[i][j] = a[i][j]+max(dp4[i][j+1], dp4[i-1][j]);

	int ans = 0;
	for(int i = 2; i < n; i++)
	  for(int j  = 2; j < m; j++)
	  {
		  ans = max(ans, dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1]);
		  ans = max(ans, dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]);
	  }
	cout<<ans<<endl;
	}
	return 0;
}
