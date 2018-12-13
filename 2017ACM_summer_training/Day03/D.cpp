//2017-08-16
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;
//dp[i][j]表示选取某些数使其和为i的时候，能否组成j。转移方程：dp[i][j] = dp[i][j+arr[p]] = 1 | dp[i-arr[p]][j] == 1
int arr[N], dp[N][N], ans[N], tot;
int n, k;
bool vis[N], book[N];

int main()
{
	while(cin>>n>>k){
		for(int i = 0; i < n; i++){
		  	cin>>arr[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int p =  0; p < n; p++){
			for(int i = k; i >= arr[p]; i--){
				for(int j = 0; j+arr[p] <= k; j++)
					if(dp[i-arr[p]][j]){
						dp[i][j] = dp[i][j+arr[p]] = 1;
					}
			}
		}
		tot = 0;
		for(int j = 0; j <= k; j++){
			if(dp[k][j])ans[tot++] = j;
		}
		cout<<tot<<endl;
		for(int i = 0; i < tot; i++)
		  	if(i == tot-1)cout<<ans[i]<<endl;
			else cout<<ans[i]<<" ";
	}

	return 0;
}
