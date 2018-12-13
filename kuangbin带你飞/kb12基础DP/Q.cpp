//2017-04-20
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
char ch[N][N];
int dp[N][N];

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n)
	{
		for(int i = 0; i < n; i++)
			scanf("%s", ch[i]);
		int ans = 1;
		for(int i = 0; i < n; i++)
		{
			for(int j = n-1; j >= 0; j--)
			{
				if(i == 0 || j == n-1)
				{
					dp[i][j] = 1;
					continue;
				}
				int u, r, cnt = 1;
				for(int k = 1; k <= dp[i-1][j+1]; k++){
					u = i-k;
					r = j+k;
					if(ch[u][j] == ch[i][r])cnt++;
					else break;
				}
				dp[i][j] = min(dp[i-1][j+1]+1, cnt);
				if(ans < dp[i][j])ans = dp[i][j];
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
