//2016.9.16
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 1005

using namespace std;

const int inf = 0x3f3f3f3f;
int edge[N][N], vis[N], num[N], low[N], n, m, Index, ans, root;//vis表示连通的集合。

void tarjan(int cur, int fa)
{
	Index++;
	num[cur] = low[cur] = Index;
	vis[cur] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(edge[cur][i]!=inf)
		{
			if(num[i] == 0)
			{
				tarjan(i, cur);
				low[cur] = min(low[cur], low[i]);
				if(low[i]>num[cur])
				  	if(ans>edge[cur][i])
					  	ans = edge[cur][i];
			}else if(i != fa)
			{
				low[cur] = min(low[cur], num[i]);
			}
		}
	}
	return;
}

int main()
{
	int u, v, w;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		if(!n && !m)break;
		memset(edge, inf, sizeof(edge));//图权值为inf表示断开
		memset(num, 0, sizeof(num));
		memset(low, 0, sizeof(low));
		memset(vis, 0, sizeof(vis));
		Index = 0, root = 1, ans = inf;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			if(edge[u][v] == inf)
			{
				edge[u][v] = w;
				edge[v][u] = w;
			}else//如果重边，必不为割边，但也不为断开，把权值设为inf一半
			{
				edge[u][v] = inf/2;
				edge[v][u] = inf/2;
			}
		}
		tarjan(1, root);
		bool fg = true;//判断图是否连通
		for(int i = 1; i <= n; i++)
		  	if(!vis[i])
			{
				printf("0\n");
				fg = false;
				break;
			}
		if(!fg)continue;
		if(ans == inf || ans == inf/2)printf("-1\n");
		else if(ans == 0)printf("1\n");//若无守兵，至少派一人去
		else printf("%d\n", ans);
	}

    return 0;
}
