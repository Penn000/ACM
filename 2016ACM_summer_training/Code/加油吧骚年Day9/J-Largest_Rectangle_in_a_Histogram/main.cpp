//2016.8.23
#include<iostream>
#include<cstdio>
#define ll __int64

using namespace std;

const int N = 100005;
ll h[N];
int l[N], r[N];//l[i]表示i点向左能够扩展的最远点下标,r[i]表示i点向右最远点下标

int main()
{
	int n;
	while(cin>>n&&n)
	{
		for(int i = 1; i <= n; i++)
			scanf("%I64d", &h[i]);
		l[1] = 1, r[n] = n;//初始化边界
		for(int i = 2; i <= n; i++)//只要高度比h[i]高，一直向左扩展
		{
			int tmp = i;
			while(tmp>1 && h[tmp-1] >= h[i])tmp = l[tmp-1];
			l[i] = tmp;
		}
		for(int i = n-1; i >= 1; i--)//只要高度比h[i]高，一直向右扩展
		{
			int tmp = i;
			while(tmp<n && h[tmp+1] >= h[i])tmp = r[tmp+1];
			r[i] = tmp;
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ll tmp = h[i]*(r[i]-l[i]+1);//矩形面积，高×底
			if(ans < tmp)ans = tmp;
		}
		printf("%I64d\n", ans);	
	}

	return 0;
}
