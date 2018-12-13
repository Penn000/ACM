//2017-05-22
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[110][110];//dp[l][r]表示区间l-r中括号匹配数
//若位置l和r匹配，dp[l][r] = max(dp[l][r], dp[l+1][r-1]+2)
//否则，dp[l][r] = max(dp[l][r], dp[l][k]+dp[k+1][r]

int main()
{
	string str;
	while(cin>>str) 
	{
		if(str[0] == 'e')break;
		int n = str.length();
		memset(dp, 0, sizeof(dp));
		for(int len = 1; len < n; len++){
			for(int i = 0; i+len < n; i++){
				int j = i+len;
				if((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']'))dp[i][j] = max(dp[i][j], dp[i+1][j-1]+2);
				for(int k = i; k <= j; k++)
				  dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
		}
		cout<<dp[0][n-1]<<endl;
	}

	return 0;
}
