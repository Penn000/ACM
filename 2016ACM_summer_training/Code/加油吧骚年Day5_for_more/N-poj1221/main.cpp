//2016.8.22
#include<cstdio>
#include<cstring>
#define ll long long

using namespace std;

const int N = 505;
ll dp[N][N];

int main()
{
	int n;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i < N; i++)
	  	dp[0][i] = 1;
	for(int i = 1; i < N; i++)
		for(int j = i/2+1; j <= i; j++)
		  	dp[i][j] = 1;
	for(int i = 2; i < N; i++)
	  	for(int j = i/2; j > 0; j--)
		  	dp[i][j] = dp[i-2*j][j]+dp[i][j+1];
	while(scanf("%d", &n)!=EOF && n)
	{
		printf("%d %lld\n", n, dp[n][1]);
	}

	return 0;
}
