//2016.8.6
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;
ll a[70], dp[70][70];

int main()
{
	int T, n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i = 0; i < n; i++)
		  scanf("%lld", &a[i]);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			  if(j-i<=20)
				dp[i][j] = a[i]*(1<<(j-i+1));
			  else 
				dp[i][j] = inf;

//		for(int i = n-1; i >=0; i--)
//		  for(int j = n-1; j >= i; j--)
//			for(int k = i; k < j; k++)
//			  dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
		for(int i = 0; i < n; i++)
  		  for(int j = 0; j < n; j++)
			for(int k = i; k < j; k++)
  			  dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);	

		cout<<dp[0][n-1]<<endl;
	}

	return 0;
}
