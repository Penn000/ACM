//2017-05-24
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[1010], dp[1010];

int main()
{
    int n, m;
	while(cin>>n&&n){
		for(int i = 1; i <= n; i++)cin>>a[i];
		cin>>m;
		sort(a+1, a+n+1);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i < n; i++)
		  	for(int j = m-5; j >= a[i]; j--)
			  	dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
		if(m<5)cout<<m<<endl;
		else cout<<(m-dp[m-5]-a[n])<<endl;
	}

	return 0;
}
