//2016.8.5
//HDU2191 多重背包问题
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int p[105], h[105], c[105];
int dp[105];

void zeroOnePack(int c, int w, int n)
{
	for(int i = n; i>= c; i--)
	  dp[i] = max(dp[i], dp[i-c]+w);
}

void completePack(int c, int w, int n)
{
	for(int i = c; i <= c; i++)
	  dp[i] = max(dp[i], dp[i-c]+w);
}

int multiplePack(int c[], int w[], int num[], int n, int m)
{
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= m; i++)
	{
		if(c[i]*num[i]>=n)
		  completePack(c[i], w[i], n);
		int k = 1;
		while(k<num[i])
		{
			zeroOnePack(k*c[i], k*w[i], n);
			num[i]-=k;
			k*=2;
		}
		zeroOnePack(num[i]*c[i], num[i]*w[i], n);
	}
	return dp[n];
}

int main()
{
	int T, n, m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &p[i], &h[i], &c[i]);
		}
		cout<<multiplePack(p, h, c, n, m)<<endl;
	}

	return 0;
}
