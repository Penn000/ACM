#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define kuai 230

using namespace std;

int arr[50005],n;
int sum[305];
void add(int x,int y)
{
	int belong=x/kuai;
	sum[belong]+=y;
	arr[x]+=y;
	return;
}
int query(int x,int y)
{
	int l=0,r=kuai-1,ans=0;
	for (int i=0;i<kuai;i++,l+=kuai,r+=kuai)
	{
		int L,R;
		L=max(l,x);
		R=min(r,y);
		if (L>R) continue;
		if (L==l && R==r)
			ans+=sum[i];
		else
		{
			for (int j=L;j<=R;j++)
				ans+=arr[j];
		}
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	for (int cas=1;cas<=t;cas++)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		memset(sum,0,sizeof(sum));
		for (int i=1;i<=n;i++)
		{
			int belong=i/230;
			sum[belong]+=arr[i];
		}
		char ch[10];
		printf("Case %d:\n",cas);
		scanf("%s",ch);
		while (ch[0]!='E')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (ch[0]=='A')
				add(x,y);
			else
			if (ch[0]=='S')
				add(x,-y);
			else
			printf("%d\n",query(x,y));
			scanf("%s",ch);
		}
	}
}
