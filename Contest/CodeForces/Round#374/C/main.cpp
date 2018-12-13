#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 5005

using namespace std;

int G[N][N];
struct node
{
	int fa, cnt, time, sp;
	node(int f, int s, int c, int t):fa(f), cnt(c), time(t), sp(s){}
};

int main()
{
	int n, m, T, u, v, t;
	while(scanf("%d%d%d", &n, &m, &T)!=EOF)
	{
		memset(G, 0, sizeof(G));
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &u, &v, &t);
			G[u][v] = t;
		}
		node start(-1, 1, 1, 0);
		queue<node> q;
		q.push(start);
		while(!q.empty())
		{
			node tmp = q.front();
			q.pop();
			int u = tmp.sp, t = tmp.time, c = tmp.;
			for(int i = 1; i <= n; i++)
			{
				if(!G[u][i])
				{
					if(tmp.time+G[u][i] > T)continue;
					q.push(node()
				}
			}
		}
	}

    return 0;
}
