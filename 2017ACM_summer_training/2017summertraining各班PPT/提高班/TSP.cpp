#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<stack>
using namespace std;
typedef long long LL;
int n;
int dis[20][20];
int dp[20][1<<16];
int min(int x,int y)
{
	if (x==-1) return y;
	if (y==-1) return x;
	if (x<=y) return x;
	return y;
}
int main()
{
	while(scanf("%d",&n) && n)
	{
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			cin>>dis[i][j];
		for(int k=0;k<=n;k++)
			for(int i=0;i<=n;i++)
				for(int j=0;j<=n;j++)
				if (i!=j && j!=k && i!=k)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		n++;
		memset(dp,-1,sizeof(dp));
		dp[0][0]=0;
		for(int state=0;state<(1<<n);state++)
		{
			for(int i=0;i<n;i++)
			if (dp[i][state]!=-1)
			{
				for(int j=0;j<n;j++)
				if (((1<<j)&state)==0)
				{
					dp[j][state|(1<<j)]=min(dp[j][state|(1<<j)],dp[i][state]+dis[i][j]);
				}
			}
		}
		int ans=dp[0][(1<<n)-1];
		cout<<ans<<endl;
	}
}
