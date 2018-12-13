//2017-05-23
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int arr[110], dp[110][110];//dp[i][j]表示区间i到j的最小价值

int main()
{
    int n;
	while(scanf("%d", &n)==1){
		for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
		for(int i = 0; i+2 < n; i++)dp[i][i+2] = arr[i]*arr[i+1]*arr[i+2];
		for(int len = 3; len < n; len++){
			for(int i = 0; i+len < n; i++){
				int j = i+len;
				dp[i][j] = inf;
				for(int k = i+1; k < j; k++){
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k]);
				}
			}
		}
		printf("%d\n", dp[0][n-1]);
	}

	return 0;
}
