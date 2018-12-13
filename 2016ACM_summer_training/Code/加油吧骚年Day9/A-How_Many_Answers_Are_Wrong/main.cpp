//2016.8.9
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int fa[200005], dis[200005], ans;

int getf(int a)
{
	if(fa[a] == -1)return a;
	int tmp = getf(fa[a]);
	dis[a] += dis[fa[a]];
	return fa[a] = tmp;
}

int Merge(int a, int b, int sum)
{
	int af = getf(a);
	int bf = getf(b);
	if(af != bf)
	{
		fa[bf] = af;
		dis[bf] = dis[a]-dis[b]+sum;
	}else
	{
		if(dis[b]-dis[a]!=sum)
		  ans++;
	}
}

int main()
{
	int n, m, a,  b, s;
	while(cin>>n>>m)
	{
		ans = 0;
		memset(dis, 0, sizeof(dis));
		memset(fa, -1, sizeof(fa));
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &s);
			a = a-1;
			Merge(a, b, s);
		}
		cout<<ans<<endl;
	}

	return 0;
}
