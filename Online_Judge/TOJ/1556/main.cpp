//2016.9.16
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1005

using namespace std;

struct edge
{
	int tar;
	edge *nex;
}*head[N], *eg, edges[N*N];

int fl[N];

void add(int a, int b)
{
	eg->tar = b;
	eg->nex = head[a];
	head[a] = eg++;
}

void dfs(int k, int x)
{
	fl[k] = x;
	for(edge *i = head[k]; i != NULL; i = i->nex)
	{
		if(i->tar==x || fl[i->tar]==x)continue;
		dfs(i->tar, x);
	}
}

int main()
{
	int kase = 0, a, b;
	while(1)
	{
		memset(head, 0, sizeof(head));
		eg = edges;
		int n = 0;//n用来记录有多少个节点
		while(scanf("%d", &a)&&a)
		{
			scanf("%d", &b);
			n = max(n, max(a, b));
			a--, b--;//编号从0开始，a、b都减1
			add(a, b);//无向图
			add(b, a);
		}
		if(!n)return 0;//如果有0个节点，返回
		if(kase)printf("\n");
		printf("Network #%d\n", ++kase);
		bool fg = false;
		memset(fl, -1, sizeof(fl));
		for(int i = 0; i < n; i++)
		{
			if(head[i] == NULL)continue;
			int cnt = 0;
			for(int j = 0; j < n; j++)
			{
				if(i == j)continue;
				if(head[j] == NULL)continue;
				if(fl[j] < i)
				{
					cnt++;
					dfs(j, i);
				}
			}
			if(cnt > 1)
			{
				printf("  SPF node %d leaves %d subnets\n", i+1, cnt);
				fg = true;
			}
		}
		if(!fg)printf("  No SPF nodes\n");
	}

    return 0;
}
