//2017-05-23 WA
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[110];
long long dp[110][110];
const int inf = 0x3f3f3f3f;

int main()
{
    int n;
	while(scanf("%d", &n)==1){
		for(int i = 0; i < n; i++)
		  	scanf("%d", &arr[i]);
		memset(dp, inf, sizeof(dp));
		for(int i = 0; i < n-2; i++)
		  	dp[i][i+2] = arr[i]*arr[i+1]*arr[i+2];
		for(int len = 3; len <= n; len++){
			for(int l = 0; l+len < n; l++){
				int r = l+len;
				dp[l][r] = min(dp[l][r-1]+arr[l]*arr[r-1]*arr[r], dp[l+1][r]+arr[l]*arr[l+1]*arr[r]);
			}
		}
		cout<<dp[0][n-1]<<endl;
	}

	return 0;
}
