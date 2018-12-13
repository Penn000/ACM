#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm> 
using namespace std;
int n,m;
int arr[1005][1005];
int brr[1005][1005];
int can_hang(int arr[1005][1005],int sx,int sy,int tx,int ty,int i)
{
	int l,r;
	l=i; r=sx;
	if (l>r) swap(l,r);
	for (int t=l;t<=r;t++)
	{
		if (arr[t][sy]!=0 && (t!=sx || sy!=sy) && (t!=tx || sy!=ty))
			return 0;
	}
	l=i; r=tx;
	if (l>r) swap(l,r);
	for (int t=l;t<=r;t++)
	{
		if (arr[t][ty]!=0 && (t!=sx || ty!=sy) && (t!=tx || ty!=ty))
			return 0;
	}
	l=sy; r=ty;
	if (l>r) swap(l,r);
	for (int t=l;t<=r;t++)
	{
		if (arr[i][t]!=0 && (i!=sx || t!=sy) && (i!=tx || t!=ty))
			return 0;
	}
	return 1;
}
int main()
{
	while (cin>>n>>m)
	{
		if (n==0 || m==0) break;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				cin>>arr[i][j];
				brr[j][i]=arr[i][j];
			}
		int q;
		cin>>q;
		int sx,sy,tx,ty;
		while (q--)
		{
			cin>>sx>>sy>>tx>>ty;
			if ((sx==tx && sy==ty) || arr[sx][sy]!=arr[tx][ty] || arr[sx][sy]==0)
			{
				cout<<"NO"<<endl;
				continue;
			}
			int flag=0;
			for (int i=1;i<=n && !flag;i++)
			{
				if (can_hang(arr,sx,sy,tx,ty,i))
					flag=1;
			}
			for (int i=1;i<=m && !flag;i++)
			{
				if (can_hang(brr,sy,sx,ty,tx,i))
					flag=1;
			}
			if (flag) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
