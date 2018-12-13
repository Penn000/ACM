//2017-04-04
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10000;
int dp[N][N];//LCS, dp[i][j]表示a[0~i]和b[0~j]的公共子序列长度

int main()
{
	string a, b;
	int n, m;
	while(cin>>a>>b)
	{
		n = a.length();
		m = b.length();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i] == b[j])dp[i+1][j+1] = dp[i][j]+1;
				else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
		cout<<dp[n][m]<<endl;
	}

    return 0;
}
