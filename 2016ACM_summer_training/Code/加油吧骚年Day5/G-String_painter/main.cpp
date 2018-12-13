//2016.8.6
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[105][105], dp2[105];
char s1[105], s2[105];

int main()
{
	while(scanf("%s%s", s1, s2)==2)
	{
		int n = strlen(s1);
		memset(dp, 0, sizeof(dp));
//		for(int i = 0; i < n; i++)
//		  for(int j = i; i < n; j++)
//			dp[i][j] = j-i+1;
		for(int j = 0; j < n; j++)
		{
			for(int i = j; i >= 0; i--)
			{
				dp[i][j] = dp[i+1][j]+1;
				for(int k = i+1; k <= j; k++)
				  if(s2[k]==s2[i])
					dp[i][j] = min(dp[i][j], dp[i+1][k]+dp[k+1][j]);
			}
		}
		for(int i = 0; i < n; i++)
		  dp2[i] = dp[0][i];
		for(int i = 0; i < n; i++)
		{
			if(s1[i]==s2[i])dp2[i] = dp2[i-1];
			else 
			{
				for(int j = 0; j < i; j++)
				{
					dp2[i] = min(dp2[i], dp2[j]+dp[j+1][i]);
				}
			}
		}
		cout<<dp2[n-1]<<endl;
	//	cout<<dp[0][n-1]<<endl;
	}

	return 0;
}
