//2016.9.16
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1005

using namespace std;

int e[N][N], match[N], book[N], k, n, m;

int dfs(int u)
{
	for(int i = 1; i <= n; i++)
	{
		if(book[i]==0 && e[u][i]==1)
		{
			book[i] = 1;
			if(match[i] == 0 || dfs(match[i]))
			{
				match[i] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int a, b;
	while(scanf("%d", &k)!=EOF && k)
	{
		int ans = 0;
		scanf("%d%d", &m, &n);
		memset(e, 0, sizeof(e));
		for(int i = 0; i < k; i++)
		{
			scanf("%d%d", &a, &b);
			e[a][b] = 1;
		}
		memset(match, 0, sizeof(match));
		for(int i = 1; i <= m; i++)
		{
			memset(book, 0, sizeof(book));
			if(dfs(i))ans++;//找到一条增广路
		}
		printf("%d\n", ans);
	}

    return 0;
}
