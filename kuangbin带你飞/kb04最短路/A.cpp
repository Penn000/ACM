//2017-07-18
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1010;
const int inf = 0x3f3f3f3f;
int t, n, G[N][N], dis[N], vis[N];

void dijkstra(int s, int d)
{
    for(int i = 1; i <= n; i++)
        dis[i] = G[s][i];
    dis[s] = 0;
	vis[s] = 1;
    int mindis, u;
    for(int i = 1; i <= n; i++)
    {
        mindis = inf;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && dis[j] < mindis)
            {
                mindis = dis[j];
                u = j;
            }
        vis[u] = 1;
        for(int v = 1; v <= n; v++)
        {
            if(dis[v] > dis[u]+G[u][v]){
                dis[v] = dis[u]+G[u][v];
            }
        }
    }
}

int main()
{
    int s, d, u, v, w;
    while(cin>>t>>n)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                  G[i][j] = inf;
            dis[i] = inf;
			vis[i] = 0;
        }
        for(int i = 0; i < t; i++)
        {
            cin>>u>>v>>w;
			if(G[u][v] > w)
            	G[u][v] = G[v][u] = w;
        }
        dijkstra(n, 1);
		cout<<dis[1]<<endl;
    }

    return 0;
}
