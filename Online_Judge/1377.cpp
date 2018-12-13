#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2000;
int dp[N][N], arr[N];
int n, m;

int main()
{
	while(cin>>n>>m){
		for(int i = 1; i <= n; i++)
		  	cin>>arr[i];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= i; j++){
				if(dp[i][j] == -1)continue;
				if(dp[i][j] >= arr[i+1])dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]-arr[i+1]);
				if(j > 0)dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]+arr[i+1]);
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			}
		}
		int ans = 0;
		for(int i = 0; i <= n; i++)
		  	ans = max(ans, dp[n][i]);
		cout<<ans<<endl;
	}

	return 0;
}
