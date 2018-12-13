//2017-04-04
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
int dp[N], a[N];//dp[i]表示前i个数字的最长上升子序列

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i = 0; i < n; i++)
		  	cin>>a[i];
		int mx = 0;
		for(int i = 0; i < n; i++){
			dp[i] = 1;
			for(int j = 0; j < i; j++){
				if(a[j] < a[i])
				  	dp[i] = max(dp[i], dp[j]+1);
			}
			mx = max(mx, dp[i]);
		}
		cout<<mx<<endl;
	}

    return 0;
}
