//2016.9.16
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 105

using namespace std;

int n, root, book[N], edge[N][N], num[N], low[N], Index;
//book用来记录哪些点是割点，edge以邻接矩阵保存图，num[i]为顶点i的时间戳，low[i]为顶点i不经过父顶点所能回到的最小时间戳

void dfs(int cur, int fa)
{
	int child = 0;
	Index++;
	num[cur] = low[cur] = Index;
	for(int i = 1; i <= n; i++)
	{
		if(edge[cur][i]==1)
		{
			if(num[i] == 0)
			{
				child++;
				dfs(i, cur);
				low[cur] = min(low[cur], low[i]);
				if(cur!=root && low[i]>=num[cur])
				  	book[cur] = 1;
				if(cur==root && child==2)
				  	book[cur] = 1;
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
	int u, v;
	while(scanf("%d", &n) && n)
	{
		memset(edge, 0, sizeof(edge));
		memset(low, 0, sizeof(low));
		memset(num, 0, sizeof(num));
		memset(book, 0, sizeof(book));
		Index = 0; root = 1;
		while(scanf("%d", &u) && u)
		{
			while(getchar() != '\n')
			{
				scanf("%d", &v);
				edge[u][v] = 1;
				edge[v][u] = 1;
			}
		}
		dfs(1, root);
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		  	if(book[i])cnt++;
		printf("%d\n", cnt);
	}

    return 0;
}
