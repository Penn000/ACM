//2016.8.5
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int A[105], B[105];
int dp[10005][16];//dp[i][j]表示跑了i个赛道，能量为j时所需的最短时间
const int inf = 9999999;

/*
int dfs(int l, int eng)
{
	if(dp[l][eng])return dp[l][eng];
	return dp[l][eng] = min(dfs(l-1,eng-1)+A[l], dfs(l-1, eng+5)+B[l]);
}*/

int main()
{
	int L, N;
	while(cin>>L>>N)
	{
		for(int i = 0; i < L; i++)
		  scanf("%d", &A[i]);
		for(int i = 0; i < L; i++)
  		  scanf("%d", &B[i]);
		memset(dp, inf, sizeof(dp));
		dp[1][1] = A[0];
		for(int i = 1; i < L*N; i++)
		{
			for(int j = 0; j < 15; j++)
			{
				int eng = j+1;
				if(eng == 15)eng = 10;
				dp[i+1][eng] = min(dp[i][j]+A[i%L], dp[i+1][eng]); 
				if(eng >= 5)dp[i+1][j-5] = min(dp[i][j]+B[i%L], dp[i+1][j-5]);
			}
		}
		int ans = inf;
		for(int i = 0; i < 15; i++)
		  if(ans>dp[L*N][i])
			ans = dp[L*N][i];
		cout<<ans<<endl;
	}

	return 0;
}
