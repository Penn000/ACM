#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005

using namespace std;

int a[N], fa[N], an[N];

bool is_an(int u, int v)
{
	if(fa[v] == u)return true;
	int tmp = v;
	while(fa[tmp]!=tmp)
	{
		tmp = fa[tmp];
		if(tmp == u)
		{
			an[v] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	int T, n, ans, u, v;
	long long k;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		memset(an, 0, sizeof(an));
		scanf("%d%lld", &n, &k);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			fa[i] = i;
		}
		for(int i = 0; i < n-1; i++)
		{
			scanf("%d%d", &u, &v);
			fa[v] = u;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i==j)continue;
				if(an[j])continue;
				if(a[i]*a[j]>k)continue;
				if(is_an(i, j))ans++;
			}
		}
		printf("%d\n", ans);
	}

    return 0;
}
