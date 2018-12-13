//2017-05-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int a[1010], dp[1010][1010];

int main()
{
	int n, m;
	while(cin>>n && n){
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		cin>>m;
		if(m < 5){
			cout<<m<<endl;
			continue;
		}
		sort(a+1, a+n+1);
		for(int i = 1; i < n; i++){
			for(int j = 1; j <= m-5; j++){
				dp[i][j] = (i==1 ? 0 : dp[i-1][j]);
				if(j >= a[i])dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]]+a[i]);
			}
		}
		cout<<(m-dp[n-1][m-5]-a[n])<<endl;
	}

	return 0;
}
