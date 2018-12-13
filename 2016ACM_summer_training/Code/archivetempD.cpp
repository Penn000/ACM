#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm> 
using namespace std;
int n;
int l[10005],c[10005];
map<int,int> dp1,dp2;
int min(int l,int r)
{
	if (l==0) return r;
	if (r==0) return l;
	return l<r?l:r;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>l[i];
	for (int i=1;i<=n;i++)
		cin>>c[i];
	for (int i=1;i<=n;i++)
	{
		dp1[l[i]]=min(dp1[l[i]],c[i]);
		map<int,int>::iterator it;
		dp2.clear();
		for (it=dp1.begin();it!=dp1.end();it++)
		{
			int key,value;
			key=it->first; value=it->second;
			dp2[__gcd(key,l[i])]=min(dp2[__gcd(key,l[i])],value+c[i]);
		}
		for (it=dp2.begin();it!=dp2.end();it++)
		{
			int key,value;
			key=it->first; value=it->second;
			dp1[key]=min(dp2[key],dp1[key]);
		}
	}
	if (dp1[1]==0) cout<<"-1"<<endl;
		else cout<<dp1[1]<<endl;
}
