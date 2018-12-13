//2016.9.22
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 205

using namespace std;

const int inf = 0x3f3f3f3f;

struct Edge
{
	int from, to , cap, flow;//分别为边的两个端点、容量、边上的流
	Edge(int u, int v, int c, int f):from(u), to(v), cap(c), flow(f){}
};

struct EdmondsKarp//Edmonds-Karp增广路算法
{
	int n, m;//结点编号0——n-1
	vector<Edge> edges;//存边与反向弧
	vector<int> G[N];//邻接表，G[i]为从i点出发的边，G[i][j]表示结点i的第j条边在数组edges中的序号
	int a[N];//当起点到i的可改进量
	int p[N];//最短路树上i的入弧编号，即记录从哪条边到达i点的

	void init(int n)//初始化
	{
		for(int i = 0; i < n; i++)G[i].clear();
		edges.clear();
	}

	void addEdge(int from, int to, int cap)//添加边
	{
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));//反向弧
		m = edges.size();
		G[from].push_back(m-2);//加入编号
		G[to].push_back(m-1);//加入编号，对应反向弧
	}

	int maxFlow(int s, int t)//最大流，s为源点，t为汇点
	{
		int flow = 0;
		while(1)
		{
			memset(a, 0, sizeof(a));
			queue<int> Q;//队列中放的是结点
			Q.push(s);
			a[s] = inf;
			while(!Q.empty())
			{
				int x = Q.front(); Q.pop();
				for(int i = 0; i < G[x].size(); i++)
				{
					Edge& e = edges[G[x][i]];
					if(!a[e.to] && e.cap>e.flow)
					{
						p[e.to] = G[x][i];
						a[e.to] = min(a[x], e.cap-e.flow);
						Q.push(e.to);
					}
				}
				if(a[t])break;
			}
			if(!a[t])break;//残余网络中不存在增广路，当前流是最大流
			for(int u = t; u != s; u = edges[p[u]].from)//找到一条增广路
			{
				edges[p[u]].flow += a[t];
				edges[p[u]^1].flow -= a[t];//p[u]^1为p[u]的反向边
			}
			flow += a[t];
		}
		return flow;
	}
};

int main()
{
	int n, m;
	EdmondsKarp e;
	while(scanf("%d%d", &m, &n)!=EOF)
	{
		int u, v, c;
		e.init(n);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &c);
			e.addEdge(u, v, c);
		}
		printf("%d\n", e.maxFlow(0, n-1));
	}

    return 0;
}
