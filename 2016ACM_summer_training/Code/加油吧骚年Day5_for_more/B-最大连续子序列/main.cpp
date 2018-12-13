#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
	int sum, l, r;
}dp[10005];
int date[10005];

int main()
{
	int n;
	while(cin>>n&&n)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", &date[i]);
		dp[0].sum = date[0];
		dp[0].l = dp[0].r = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(dp[i].sum+date[i+1]>date[i+1])
			{
				dp[i+1].sum = dp[i].sum
			}
		}
	}
	return 0;
}
