//2017-03-17
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

const int N = 510;
const int inf = 0x3f3f3f3f;
int n, m, G[N][N], dis[N], vis[N], pre[N], way[N], maxpeo[N];

int dijkstra(int s, int d)
{
	for(int i = 0; i < n; i++)
	{
		dis[i] = G[s][i];
		if(G[s][i] != inf){
			pre[i] = s;
			way[i]++;
		}
	}
	pre[s] = -1;
	dis[s] = 0;
	vis[s] = 1;
	way[s] = 1;
	int mindis,  u;
	maxpeo[s] = G[s][s];
	for(int i = 0; i < n; i++)
	{
		mindis = inf;
		for(int j = 0; j < n; j++)
			if(!vis[j] && dis[j] < mindis)
			{
				mindis = dis[j];
				u = j;
			}
		vis[u] = 1;
		for(int v = 0; v < n; v++)
		{
			if(vis[v] || G[u][v]==inf)continue;
			if(dis[v] > dis[u]+G[u][v]){
				dis[v] = dis[u]+G[u][v];
				pre[v] = u;
				maxpeo[v] = maxpeo[u] + G[v][v];
				way[v] = way[u];
			}else if(dis[v] == dis[u]+G[u][v]){
				way[v] += way[u];
				if(maxpeo[v] < maxpeo[u]+G[v][v]){
					maxpeo[v] = maxpeo[u] + G[v][v];
					pre[v] = u;
				}
			}
		}
	}
	return maxpeo[d]+maxpeo[s];
}

int main()
{
	int s, d, u, v, w;
	while(cin>>n>>m>>s>>d)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			  	G[i][j] = inf;
			vis[i] = 0;
			dis[i] = inf;
			pre[i] = -1;
			way[i] = 0;
			maxpeo[i] = 0;
			cin>>G[i][i];
			maxpeo[i] = G[i][i];
		}
		for(int i = 0; i < m; i++)
		{
			cin>>u>>v>>w;
			G[u][v] = G[v][u] = w;
		}
		int peo = dijkstra(s, d);
		int pr = d;
		stack<int> sk;
		while(pr != s)
		{
			sk.push(pr);
			pr = pre[pr];
		}
		cout<<way[d]<<" "<<peo<<endl;
		cout<<s;
		int o;
		while(!sk.empty())
		{
			o = sk.top();
			cout<<" "<<o;
			sk.pop();
		}
		cout<<endl;
	}

    return 0;
}
