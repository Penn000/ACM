#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAXN 110
#define MAXM 66
#define MOD 1000000007

using namespace std;

int n,m,deadline;
long long dp[MAXN][MAXN][MAXM];
long long ans[MAXN][MAXM];

void add_edge(int a,int b)
{
	dp[a][b][0]=dp[b][a][0]=1;
}

int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add_edge(a,b);
	}
	scanf("%d",&deadline);
	m=1;
	while(deadline>>m)m++;m--;
	for(int t=1;t<=m;t++)
	  for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
		  for(int k=1;k<=n;k++)
			dp[i][k][t]=(dp[i][k][t]+dp[i][j][t-1]*dp[j][k][t-1])%MOD;
	//for(int t=0;t<=m;t++)
	//{
	//	cout<<"t="<<t<<endl;
	//	for(int i=1;i<=n;i++)
	//	{
	//		for(int j=1;j<=n;j++)
	//		  cout<<dp[i][j][t]<<' ';
	//		cout<<endl;
	//	}
	//}
	if(deadline&1)
	{
		for(int k=1;k<=n;k++)
		  ans[k][0]=dp[1][k][0];
	}
	else ans[1][0]=1;
	for(int t=1;t<=m;t++)
	{
		if(deadline&(1<<t))
		{
			for(int j=1;j<=n;j++)
			  for(int k=1;k<=n;k++)
				ans[k][t]=(ans[k][t]+ans[j][t-1]*dp[j][k][t])%MOD;
		}
		else for(int j=1;j<=n;j++)ans[j][t]=ans[j][t-1];
	}
	printf("%lld\n",ans[n][m]<<1);
	return 0;
}
