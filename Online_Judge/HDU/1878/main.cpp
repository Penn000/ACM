//2016.9.18
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1005

using namespace std;

int G[N][N], vis[N][N], n, m, fa[N];

void init(int n)
{
	for(int i = 1; i <= n; i++)
	  	fa[i] = i;
}

int getfa(int a)
{
	if(fa[a] == a)return a;
	return fa[a] = getfa(fa[a]);
}

int Merge(int a, int b)
{
	int af = getfa(a);
	int bf = getfa(b);
	if(af!=bf)fa[bf] = af;
}

int main()
{
	int u, v;
	while(scanf("%d", &n)!=EOF && n)
	{
		scanf("%d", &m);
		memset(G, -1, sizeof(G));
		init(n);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			G[u][v] = G[v][u] = 1;
			Merge(u, v);
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)//所有节点的度必须为偶数
		{
			int idx = 0;
			for(int j = 1; j <= n; j++)
			{
				if(i == j)continue;
				if(G[i][j]==1)idx++;
			}
			if(idx&1)cnt++;
			if(cnt > 0)break;
		}
		bool fg = true;
		int ct = 0;
		for(int i = 1; i <= n; i++)//判断图是否连通
		{
			if(fa[i]==i)ct++;
			if(ct>1){
				fg = false;
				break;
			}
		}
		if(cnt == 0 && fg)printf("1\n");
		else printf("0\n");
	}

    return 0;
}
