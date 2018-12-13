//2017-09-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int a[N][N], dp[N][N], n, m, x, y;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &n, &m, &x, &y);
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++){
			  scanf("%d", &a[i][j]);
			  dp[i][j] = a[i][j];
		  }
		for(int i = 1; i < n; i++)
		  for(int j = 0; j < m; j++)
			dp[i][j] += dp[i-1][j];
		for(int j = 1; j < m; j++)
		  for(int i = 0; i < n; i++)
			dp[i][j] += dp[i][j-1];
		int ans = 0;
		for(int i = x-1; i < n; i++)
		  for(int j = y-1; j < m; j++){
			  int a = i-x+1;
			  int b = j-y+1;
			  int tmp = dp[i][j];
			  if(a-1>=0)tmp -= dp[a-1][j];
			  if(b-1>=0)tmp -= dp[i][b-1];
			  if(a-1>=0 && b-1>=0)tmp += dp[a-1][b-1];
			  ans = max(ans, tmp);
		  }
		printf("%d\n", ans);
	}

	return 0;
}
